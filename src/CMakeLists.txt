cmake_minimum_required(VERSION 2.8)
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE TYPE INTERNAL FORCE)
project("lms8suite")
#include modules for finding CyAPI
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
cmake_policy(SET CMP0015 OLD)
if(${CMAKE_MAJOR_VERSION} GREATER 2)
	cmake_policy(SET CMP0043 NEW)
endif()
ADD_DEFINITIONS(-D_CRT_SECURE_NO_WARNINGS)
if(CMAKE_COMPILER_IS_GNUCXX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
endif()

find_package(wxWidgets REQUIRED richtext xml html xrc adv aui core base gl)
include(${wxWidgets_USE_FILE})
set(wxWidgets_USE_DEBUG OFF)
set(wxWidgets_USE_UNICODE ON)
set(wxWidgets_USE_UNIVERSAL OFF)
set(wxWidgets_USE_STATIC ON)

# Add sub-directories
add_subdirectory(lms8001_wxgui)
include_directories(lms8001_wxgui)
add_subdirectory(lms8001)
include_directories(lms8001)
add_subdirectory(lms8suiteEvents)
include_directories(lms8suiteEvents)
add_subdirectory(utilities_gui)
include_directories(utilities_gui)
add_subdirectory(ADF4002)
include_directories(ADF4002) 
add_subdirectory(Si5351C)
include_directories(Si5351C)

set(BINARY_OUTPUT_DIR "${CMAKE_BINARY_DIR}/bin")

set(lms8suiteApp
	lms8suiteApp.cpp
	lms8suiteAppFrame.cpp
	lms8suiteApp_gui.cpp
	dlgAbout.cpp
	)
	
if (MSVC)
	SET( MSVC_MULTITHREAD_COMPILE_FLAGS "/MP")
	SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${MSVC_MULTITHREAD_COMPILE_FLAGS}" )
endif(MSVC)
if(WIN32)
	find_package(CyAPI REQUIRED)
	LINK_DIRECTORIES(${CYAPI_LIBRARIES})	
	include_directories(${CYAPI_INCLUDE_DIRS})
endif()

add_executable(lms8suite ${lms8suiteApp} resource.rc)

set(AUTO_UPDATE_VERSION OFF CACHE BOOL "Uses python script to increment version")
if(AUTO_UPDATE_VERSION)
	add_custom_target(updateVersion ALL COMMAND python ${CMAKE_CURRENT_SOURCE_DIR}/auto_version.py WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})	
	add_dependencies(lms8suite updateVersion)
endif()

set_target_properties(lms8suite
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${BINARY_OUTPUT_DIR})
	
target_link_libraries(
    lms8suite 
	ADF4002 	
	Si5351C 	
	lms8001_wxgui 
	LMS8001 
	utilities_gui 	
	lms8suiteEvents 
	${CYAPI_LIBRARIES}
	${wxWidgets_LIBRARIES}
	)

if(UNIX)	
	set(CONNECTION_MANAGER_LIBS usb-1.0 -lpthread)
	target_link_libraries(lms8suite ${CONNECTION_MANAGER_LIBS})
endif()

if (MSVC)
	set_property(TARGET lms8suite APPEND PROPERTY LINK_FLAGS /SUBSYSTEM:WINDOWS)
endif(MSVC)
