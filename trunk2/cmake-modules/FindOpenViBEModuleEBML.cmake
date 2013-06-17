# ---------------------------------
# Finds module EBML
# Adds library to target
# Adds include path
# ---------------------------------
OPTION(DYNAMIC_LINK_OPENVIBE_MODULE_EBML "Dynamically link OpenViBE module EBML" ON)

IF(DYNAMIC_LINK_OPENVIBE_MODULE_EBML)
	SET(OPENVIBE_MODULE_EBML_LINKING "")
ELSE(DYNAMIC_LINK_OPENVIBE_MODULE_EBML)
	SET(OPENVIBE_MODULE_EBML_LINKING "-static")
ENDIF(DYNAMIC_LINK_OPENVIBE_MODULE_EBML)

set(SRC_DIR ${OV_BASE_DIR}/modules/ebml/include)

FIND_PATH(PATH_OPENVIBE_MODULES_EBML ebml/defines.h PATHS ${SRC_DIR})
IF(PATH_OPENVIBE_MODULES_EBML)
	MESSAGE(STATUS "  Found OpenViBE module EBML...")
	INCLUDE_DIRECTORIES(${PATH_OPENVIBE_MODULES_EBML}/)

	TARGET_LINK_LIBRARIES(${PROJECT_NAME} openvibe-module-ebml${OPENVIBE_MODULE_EBML_LINKING})

	ADD_DEFINITIONS(-DTARGET_HAS_EBML)
ELSE(PATH_OPENVIBE_MODULES_EBML)
	MESSAGE(STATUS "  FAILED to find OpenViBE module EBML...")
ENDIF(PATH_OPENVIBE_MODULES_EBML)