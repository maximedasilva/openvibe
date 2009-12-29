#include "ovp_defines.h"
#include "ovpCGDFFileReader.h"
#include "ovpCGDFFileWriter.h"
#include "ovpCBCICompetitionIIIbReader.h"

#include "algorithms/file-reading-and-writing/brainamp/ovpCAlgorithmBrainampFileReader.h"

#include "algorithms/file-reading-and-writing/ovpCAlgorithmOVMatrixFileReader.h"
#include "algorithms/file-reading-and-writing/ovpCAlgorithmOVMatrixFileWriter.h"

#include "algorithms/file-reading-and-writing/xml-scenario/ovpCAlgorithmXMLScenarioExporter.h"
#include "algorithms/file-reading-and-writing/xml-scenario/ovpCAlgorithmXMLScenarioImporter.h"

#include "box-algorithms/file-reading-and-writing/brainamp/ovpCBoxAlgorithmBrainampFileReader.h"

#include "box-algorithms/file-reading-and-writing/csv/ovpCBoxAlgorithmCSVFileWriter.h"

#include "box-algorithms/file-reading-and-writing/openvibe/ovpCBoxAlgorithmGenericStreamReader.h"
#include "box-algorithms/file-reading-and-writing/openvibe/ovpCBoxAlgorithmGenericStreamWriter.h"

#include "box-algorithms/file-reading-and-writing/ovpCBoxAlgorithmElectrodeLocalizationFileReader.h"

OVP_Declare_Begin()
	OVP_Declare_New(OpenViBEPlugins::FileIO::CGDFFileReaderDesc)
	OVP_Declare_New(OpenViBEPlugins::FileIO::CGDFFileWriterDesc)

	OVP_Declare_New(OpenViBEPlugins::FileIO::CBCICompetitionIIIbReaderDesc)

	OVP_Declare_New(OpenViBEPlugins::FileIO::CAlgorithmBrainampFileReaderDesc)

	OVP_Declare_New(OpenViBEPlugins::FileIO::CAlgorithmOVMatrixFileReaderDesc)
	OVP_Declare_New(OpenViBEPlugins::FileIO::CAlgorithmOVMatrixFileWriterDesc)

	OVP_Declare_New(OpenViBEPlugins::FileIO::CAlgorithmXMLScenarioExporterDesc)
	OVP_Declare_New(OpenViBEPlugins::FileIO::CAlgorithmXMLScenarioImporterDesc)

	OVP_Declare_New(OpenViBEPlugins::FileIO::CBoxAlgorithmBrainampFileReaderDesc)

	OVP_Declare_New(OpenViBEPlugins::FileIO::CBoxAlgorithmCSVFileWriterDesc)

	OVP_Declare_New(OpenViBEPlugins::FileIO::CBoxAlgorithmGenericStreamReaderDesc)
	OVP_Declare_New(OpenViBEPlugins::FileIO::CBoxAlgorithmGenericStreamWriterDesc)

	OVP_Declare_New(OpenViBEPlugins::FileIO::CBoxAlgorithmElectrodeLocalisationFileReaderDesc)
OVP_Declare_End()