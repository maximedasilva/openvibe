# ---------------------------------
# Finds CEGUI toolkit
#
# Sets CEGUI_FOUND
# Sets CEGUI_LIBRARIES
# Sets CEGUI_LIBRARY_DIRS
# Sets CEGUI_LDFLAGS
# Sets CEGUI_LDFLAGS_OTHERS
# Sets CEGUI_INCLUDE_DIRS
# Sets CEGUI_CFLAGS
# Sets CEGUI_CFLAGS_OTHERS
# ---------------------------------

INCLUDE("FindThirdPartyPkgConfig")
pkg_check_modules(CEGUI CEGUI)

IF(CEGUI_FOUND)
	MESSAGE(STATUS "  Found CEGUI...")
	INCLUDE_DIRECTORIES(${CEGUI_INCLUDE_DIRS})
	ADD_DEFINITIONS(${CEGUI_CFLAGS})
	ADD_DEFINITIONS(${CEGUI_CFLAGS_OTHERS})
	LINK_DIRECTORIES(${CEGUI_LIBRARY_DIRS})
	FOREACH(CEGUI_LIB ${CEGUI_LIBRARIES})
		SET(CEGUI_LIB1 "CEGUI_LIB1-NOTFOUND")
		FIND_LIBRARY(CEGUI_LIB1 NAMES ${CEGUI_LIB} PATHS ${CEGUI_LIBRARY_DIRS} ${CEGUI_LIBDIR} NO_DEFAULT_PATH)
		FIND_LIBRARY(CEGUI_LIB1 NAMES ${CEGUI_LIB})
		IF(CEGUI_LIB1)
			MESSAGE(STATUS "    [  OK  ] Third party lib ${CEGUI_LIB1}")
			TARGET_LINK_LIBRARIES(${PROJECT_NAME}-dynamic ${CEGUI_LIB1})
		ELSE(CEGUI_LIB1)
			MESSAGE(STATUS "    [FAILED] Third party lib ${CEGUI_LIB}")
		ENDIF(CEGUI_LIB1)
	ENDFOREACH(CEGUI_LIB)
ELSE(CEGUI_FOUND)
	MESSAGE(STATUS "  FAILED to find CEGUI...")
ENDIF(CEGUI_FOUND)