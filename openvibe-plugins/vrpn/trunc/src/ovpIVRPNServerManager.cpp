#if defined TARGET_HAS_ThirdPartyVRPN

#include "ovpIVRPNServerManager.h"

#include <vrpn_Connection.h>
#include <vrpn_Analog.h>
#include <vrpn_Button.h>

#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace OpenViBE;
using namespace OpenViBE::Plugins;
using namespace OpenViBE::Kernel;
using namespace OpenViBEPlugins;
using namespace OpenViBEPlugins::VRPN;
using namespace std;

#define boolean OpenViBE::boolean

namespace OpenViBEPlugins
{
	namespace VRPN
	{
		namespace
		{
			class CVRPNServerManager : virtual public IVRPNServerManager
			{
			public:

				CVRPNServerManager(void);
				virtual ~CVRPNServerManager(void);

				virtual boolean initialize(void);
				virtual boolean uninitialize(void);

				virtual boolean process(void);

				virtual boolean addServer(
					const CString& sServerName,
					CIdentifier& rServerIdentifier);
				virtual boolean isServer(
					const CIdentifier& rServerIdentifier);
				virtual boolean isServer(
					const CString& sServerName);
				virtual boolean getServerIdentifier(
					const CString& sServerName,
					CIdentifier& rServerIdentifier);
				virtual boolean getServerName(
					const CIdentifier& rServerIdentifier,
					CString& sServerName);
				virtual boolean removeServer(
					const CIdentifier& rServerIdentifier);

				virtual boolean setButtonCount(
					const CIdentifier& rServerIdentifier,
					const uint32 ui32ButtonCount);
				virtual boolean setButtonState(
					const CIdentifier& rServerIdentifier,
					const uint32 ui32ButtonIndex,
					const boolean bButtonStatus);

				virtual boolean setAnalogCount(
					const CIdentifier& rServerIdentifier,
					const uint32 ui32AnalogCount);
				virtual boolean setAnalogState(
					const CIdentifier& rServerIdentifier,
					const uint32 ui32AnalogIndex,
					const float64 f64AnalogStatus);

			protected:

				vrpn_Connection* m_pConnection;

				map<CIdentifier, CString> m_vServerName;
				map<CIdentifier, vrpn_Button_Server*> m_vButtonServer;
				map<CIdentifier, vrpn_Analog_Server*> m_vAnalogServer;

				uint32 m_ui32InitializeCount;
			};
		};

		IVRPNServerManager& IVRPNServerManager::getInstance()
		{
			static CVRPNServerManager g_oVRPNServerManager;
			return g_oVRPNServerManager;
		}
	};
};

CVRPNServerManager::CVRPNServerManager(void)
	:m_pConnection(NULL)
	,m_ui32InitializeCount(0)
{
}

CVRPNServerManager::~CVRPNServerManager(void)
{
}

boolean CVRPNServerManager::initialize(void)
{
	if(!m_ui32InitializeCount)
	{
		m_pConnection=new vrpn_Connection;
	}
	m_ui32InitializeCount++;
	return true;
}

boolean CVRPNServerManager::uninitialize(void)
{
	m_ui32InitializeCount--;
	if(!m_ui32InitializeCount)
	{
		map<CIdentifier, vrpn_Analog_Server*>::iterator itAnalogServer;
		for(itAnalogServer=m_vAnalogServer.begin(); itAnalogServer!=m_vAnalogServer.end(); itAnalogServer++)
		{
			delete itAnalogServer->second;
		}
		m_vAnalogServer.clear();
		map<CIdentifier, vrpn_Button_Server*>::iterator itButtonServer;
		for(itButtonServer=m_vButtonServer.begin(); itButtonServer!=m_vButtonServer.end(); itButtonServer++)
		{
			delete itButtonServer->second;
		}
		m_vButtonServer.clear();
		delete m_pConnection;
		m_pConnection=NULL;
	}
	return true;
}

boolean CVRPNServerManager::process(void)
{
	map<CIdentifier, vrpn_Analog_Server*>::iterator itAnalogServer;
	for(itAnalogServer=m_vAnalogServer.begin(); itAnalogServer!=m_vAnalogServer.end(); itAnalogServer++)
	{
		if(itAnalogServer->second)
		{
			// This is public function and mainloop won't call it for me
			// Thank you VRPN for this to be similar to button behavior ;o)
			itAnalogServer->second->report_changes();

			itAnalogServer->second->mainloop();
		}
	}
	map<CIdentifier, vrpn_Button_Server*>::iterator itButtonServer;
	for(itButtonServer=m_vButtonServer.begin(); itButtonServer!=m_vButtonServer.end(); itButtonServer++)
	{
		if(itButtonServer->second)
		{
			// This is not public function, however, mainloop calls it for me
			// Thank you VRPN for this to be similar to analog behavior ;o)
			// itButtonServer->second->report_changes();

			itButtonServer->second->mainloop();
		}
	}
	if(m_pConnection)
	{
		m_pConnection->mainloop();
	}
	return true;
}

boolean CVRPNServerManager::addServer(
	const CString& sServerName,
	CIdentifier& rServerIdentifier)
{
	if(this->isServer(sServerName))
	{
		return this->getServerIdentifier(sServerName, rServerIdentifier);
	}

	rServerIdentifier=CIdentifier::random();
	while(m_vServerName.find(rServerIdentifier)!=m_vServerName.end())
	{
		++rServerIdentifier;
	}

	m_vServerName[rServerIdentifier]=sServerName;
	return true;
}

boolean CVRPNServerManager::isServer(
	const CIdentifier& rServerIdentifier)
{
	return m_vServerName.find(rServerIdentifier)!=m_vServerName.end();
}

boolean CVRPNServerManager::isServer(
	const CString& sServerName)
{
	map<CIdentifier, CString>::iterator itServerName;
	for(itServerName=m_vServerName.begin(); itServerName!=m_vServerName.end(); itServerName++)
	{
		if(itServerName->second==sServerName)
		{
			return true;
		}
	}
	return false;
}

boolean CVRPNServerManager::getServerIdentifier(
	const CString& sServerName,
	CIdentifier& rServerIdentifier)
{
	map<CIdentifier, CString>::iterator itServerName;
	for(itServerName=m_vServerName.begin(); itServerName!=m_vServerName.end(); itServerName++)
	{
		if(itServerName->second==sServerName)
		{
			rServerIdentifier=itServerName->first;
			return true;
		}
	}
	return false;
}

boolean CVRPNServerManager::getServerName(
	const CIdentifier& rServerIdentifier,
	CString& sServerName)
{
	map<CIdentifier, CString>::iterator itServerName=m_vServerName.find(rServerIdentifier);
	if(itServerName==m_vServerName.end())
	{
		return false;
	}
	sServerName=itServerName->second;
	return true;
}

boolean CVRPNServerManager::removeServer(
	const CIdentifier& rServerIdentifier)
{
	if(!this->isServer(rServerIdentifier))
	{
		return false;
	}

	// TODO
	return true;
}

boolean CVRPNServerManager::setButtonCount(
	const CIdentifier& rServerIdentifier,
	const uint32 ui32ButtonCount)
{
	if(!this->isServer(rServerIdentifier))
	{
		return false;
	}
	delete m_vButtonServer[rServerIdentifier];
	m_vButtonServer[rServerIdentifier]=new vrpn_Button_Server(m_vServerName[rServerIdentifier], m_pConnection, ui32ButtonCount);
	return true;
}

boolean CVRPNServerManager::setButtonState(
	const CIdentifier& rServerIdentifier,
	const uint32 ui32ButtonIndex,
	const boolean bButtonStatus)
{
	if(!this->isServer(rServerIdentifier))
	{
		return false;
	}
	if(m_vButtonServer.find(rServerIdentifier)==m_vButtonServer.end())
	{
		return false;
	}
	m_vButtonServer[rServerIdentifier]->set_button(ui32ButtonIndex, bButtonStatus?1:0);
	return true;
}

boolean CVRPNServerManager::setAnalogCount(
	const CIdentifier& rServerIdentifier,
	const uint32 ui32AnalogCount)
{
	if(!this->isServer(rServerIdentifier))
	{
		return false;
	}
	delete m_vAnalogServer[rServerIdentifier];
	m_vAnalogServer[rServerIdentifier]=new vrpn_Analog_Server(m_vServerName[rServerIdentifier], m_pConnection);
	m_vAnalogServer[rServerIdentifier]->setNumChannels(ui32AnalogCount);
	return true;

}

boolean CVRPNServerManager::setAnalogState(
	const CIdentifier& rServerIdentifier,
	const uint32 ui32AnalogIndex,
	const float64 f64AnalogStatus)
{
	if(!this->isServer(rServerIdentifier))
	{
		return false;
	}
	if(m_vAnalogServer.find(rServerIdentifier)==m_vAnalogServer.end())
	{
		return false;
	}
	m_vAnalogServer[rServerIdentifier]->channels()[ui32AnalogIndex]=f64AnalogStatus;
	return true;
}

#endif // OVP_HAS_Vrpn