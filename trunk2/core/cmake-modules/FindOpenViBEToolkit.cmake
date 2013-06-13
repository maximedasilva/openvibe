# ---------------------------------
# Finds openvibe-toolkit
# Adds library to target
# Adds include path
# ---------------------------------
OPTION(DYNAMIC_LINK_OPENVIBE_TOOLKIT "Dynamically link openvibe-toolkit" ON)

IF(DYNAMIC_LINK_OPENVIBE_TOOLKIT)
	SET(OPENVIBE_TOOLKIT_LINKING "")
ELSE(DYNAMIC_LINK_OPENVIBE_TOOLKIT)
	SET(OPENVIBE_TOOLKIT_LINKING "-static")
ENDIF(DYNAMIC_LINK_OPENVIBE_TOOLKIT)

set(SRC_DIR ${OV_BASE_DIR}/toolkit/include)

FIND_PATH(PATH_OPENVIBE_TOOLKIT toolkit/ovtk_all.h PATHS ${SRC_DIR})
IF(PATH_OPENVIBE_TOOLKIT)
	MESSAGE(STATUS "  Found openvibe-toolkit...")
	INCLUDE_DIRECTORIES(${PATH_OPENVIBE_TOOLKIT}/)

	TARGET_LINK_LIBRARIES(${PROJECT_NAME} openvibe-toolkit${OPENVIBE_TOOLKIT_LINKING})

	ADD_DEFINITIONS(-DTARGET_HAS_OpenViBEToolkit)
ELSE(PATH_OPENVIBE_TOOLKIT)
	MESSAGE(STATUS "  FAILED to find openvibe-toolkit...")
ENDIF(PATH_OPENVIBE_TOOLKIT)


