### medPack.cmake --- 
## 
## Author: Julien Wintz
## Copyright (C) 2008 - Julien Wintz, Inria.
## Created: Thu Jun 10 10:21:17 2010 (+0200)
## Version: $Id$
## Last-Updated: Thu Jun 10 10:41:55 2010 (+0200)
##           By: Julien Wintz
##     Update #: 12
######################################################################
## 
### Commentary: 
## 
######################################################################
## 
### Change log:
## 
######################################################################


include (InstallRequiredSystemLibraries)

set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_FILE_NAME "${PROJECT_NAME}-${${PROJECT_NAME}_VERSION}")
set(CPACK_SOURCE_PACKAGE_FILE_NAME "${PROJECT_NAME}-${${PROJECT_NAME}_VERSION}-src")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY ${PROJECT_NAME})
set(CPACK_PACKAGE_DESCRIPTION ${PROJECT_NAME})

set(CPACK_PACKAGE_VENDOR "http://www.inria.fr/")
set(CPACK_PACKAGE_CONTACT "Benoît Bleuzé <Benoit.Bleuze@inria.fr>")
set(CPACK_PACKAGE_DESCRIPTION_FILE ${CMAKE_CURRENT_SOURCE_DIR}/README.txt)
set(CPACK_PACKAGE_VERSION_MAJOR ${${PROJECT_NAME}_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${${PROJECT_NAME}_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${${PROJECT_NAME}_VERSION_BUILD})
set(CPACK_RESOURCE_FILE_LICENSE ${CMAKE_CURRENT_SOURCE_DIR}/COPYING.txt)

set(CPACK_PACKAGING_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX})

set(CPACK_BINARY_STGZ OFF)
set(CPACK_BINARY_TBZ2 OFF)
set(CPACK_BINARY_TGZ OFF)
set(CPACK_BINARY_TZ OFF)

set(CPACK_SOURCE_TBZ2 OFF)
set(CPACK_SOURCE_TGZ OFF)
set(CPACK_SOURCE_TZ OFF)
set(CPACK_SOURCE_ZIP OFF)


if(UNIX AND NOT APPLE)
  set (CPACK_DEBIAN_PACKAGE_DEPENDS "dtk (>= ${${PROJECT_NAME}_VERSION_MAJOR}.${${PROJECT_NAME}_VERSION_MINOR})") 
endif(UNIX AND NOT APPLE)

IF(WIN32)
	MACRO( MAKE_NSIS_INSTALLER TARGET INPUT VERSION)
		FIND_FILE(MAKENSIS makensis.exe
			"C:/Program Files/NSIS/"        
			)                          
		IF( MAKENSIS )       
			FILE(TO_CMAKE_PATH "$ENV{SYSTEMROOT}" SYSTEMROOT)
			IF(CMAKE_CL_64)
				SET(MSVC_ARCH amd64)
			ELSE(CMAKE_CL_64)
				SET(MSVC_ARCH x86)
			ENDIF(CMAKE_CL_64)
			SET(NSIS_OPTIONS
				${NSIS_OPTIONS}
				"/DmedinriaDIR=${EXECUTABLE_OUTPUT_PATH}"
				"/DmedinriaLIBDIR=${LIBRARY_OUTPUT_PATH}/release"
				"/DVERSION=${VERSION}"
				"/DSRCDIR=${PROJECT_SOURCE_DIR}"
				"/DINST_PREFIX=${CMAKE_INSTALL_PREFIX}"
				#must be changed but ${CMAKE_INSTALL_PREFIX} has slashes not backslashes...
				
                "/DPACK_INSTALLDIR=$PROGRAMFILES\\inria"
				"/DPROJECT_NAME=${PROJECT_NAME}"
				"/DMED_EXECUTABLE=medinria.exe"
				)
			ADD_CUSTOM_COMMAND(
				TARGET ${TARGET} POST_BUILD
				COMMAND ${MAKENSIS} 
				ARGS ${NSIS_OPTIONS} ${INPUT}
				)
		ENDIF( MAKENSIS )
	ENDMACRO( MAKE_NSIS_INSTALLER )
	
	ADD_CUSTOM_TARGET(nsis  
		COMMENT "Create an installer for windows"
		DEPENDS install 
	)
    MAKE_NSIS_INSTALLER( nsis  ${PROJECT_SOURCE_DIR}/installerMedinria.nsi  ${${PROJECT_NAME}_VERSION})
ENDIF(WIN32)


include(CPack)