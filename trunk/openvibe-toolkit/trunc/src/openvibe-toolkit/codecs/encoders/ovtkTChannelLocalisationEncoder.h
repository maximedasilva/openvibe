#ifndef __OpenViBEToolkit_TChannelLocalisationEncoder_H__
#define __OpenViBEToolkit_TChannelLocalisationEncoder_H__

#ifdef TARGET_HAS_ThirdPartyOpenViBEPluginsGlobalDefines

#include "../../ovtk_base.h"

#include "ovtkTEncoder.h"

namespace OpenViBEToolkit
{
	template <class T>
	class TChannelLocalisationEncoderLocal : public T
	{
		
	protected:

		OpenViBE::Kernel::TParameterHandler < OpenViBE::IMatrix* > m_pInputLocalisationMatrix;
		OpenViBE::Kernel::TParameterHandler < OpenViBE::boolean > m_bInputDynamic;
		
		using T::m_pCodec;
		using T::m_pBoxAlgorithm;
		using T::m_pOutputMemoryBuffer;

		OpenViBE::boolean initializeImpl()
		{
			m_pCodec = &m_pBoxAlgorithm->getAlgorithmManager().getAlgorithm(m_pBoxAlgorithm->getAlgorithmManager().createAlgorithm(OVP_GD_ClassId_Algorithm_ChannelLocalisationStreamEncoder));
			m_pCodec->initialize();
			m_pInputLocalisationMatrix.initialize(m_pCodec->getInputParameter(OVP_GD_Algorithm_ChannelLocalisationStreamEncoder_InputParameterId_Matrix));
			m_bInputDynamic.initialize(m_pCodec->getInputParameter(OVP_GD_Algorithm_ChannelLocalisationStreamEncoder_InputParameterId_Dynamic));
			m_pOutputMemoryBuffer.initialize(m_pCodec->getOutputParameter(OVP_GD_Algorithm_ChannelLocalisationStreamEncoder_OutputParameterId_EncodedMemoryBuffer));

			return true;
		}

	public:
		using T::initialize;
		
		OpenViBE::boolean uninitialize(void)
		{
			if(m_pBoxAlgorithm == NULL || m_pCodec == NULL)
			{
				return false;
			}

			m_pInputLocalisationMatrix.uninitialize();
			m_bInputDynamic.uninitialize();
			m_pOutputMemoryBuffer.uninitialize();
			m_pCodec->uninitialize();
			m_pBoxAlgorithm->getAlgorithmManager().releaseAlgorithm(*m_pCodec);
			m_pBoxAlgorithm = NULL;

			return true;
		}

		OpenViBE::Kernel::TParameterHandler < OpenViBE::IMatrix* >& getInputMatrix()
		{
			return m_pInputLocalisationMatrix;
		}

		OpenViBE::Kernel::TParameterHandler < OpenViBE::boolean >& getInputDynamic()
		{
			return m_bInputDynamic;
		}

	protected:
		OpenViBE::boolean encodeHeaderImpl(void)
		{
			return m_pCodec->process(OVP_GD_Algorithm_ChannelLocalisationStreamEncoder_InputTriggerId_EncodeHeader);
		}

		OpenViBE::boolean encodeBufferImpl(void)
		{
			return m_pCodec->process(OVP_GD_Algorithm_ChannelLocalisationStreamEncoder_InputTriggerId_EncodeBuffer);
		}

		OpenViBE::boolean encodeEndImpl(void)
		{
			return m_pCodec->process(OVP_GD_Algorithm_ChannelLocalisationStreamEncoder_InputTriggerId_EncodeEnd);
		}
	};

	template <class T>
	class TChannelLocalisationEncoder : public TChannelLocalisationEncoderLocal < TEncoder < T > >
	{
	};
};

#endif // TARGET_HAS_ThirdPartyOpenViBEPluginsGlobalDefines

#endif //__OpenViBEToolkit_TChannelLocalisationEncoder_H__