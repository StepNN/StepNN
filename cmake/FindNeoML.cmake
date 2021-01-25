# Cmake script to detect ABBYY NeoML library
#
# Variables list:
# NeoML_ROOT - directory where NeoML include/lib files are stored

if(ENV{NeoML_ROOT} STREQUAL "")
	message(FATAL_ERROR "NeoML_ROOT is empty!")
endif()

if (${CMAKE_BUILD_TYPE} MATCHES "Debug")
	set(NeoML_LIB_DIR_SUFFIX "lib/debug")
else()
	set(NeoML_LIB_DIR_SUFFIX "lib/release")
endif()

find_path(NeoML_INCLUDE_DIR NAMES NeoML/NeoML.h NeoMathEngine/NeoMathEngine.h HINTS ENV{NeoML_ROOT} PATH_SUFFIXES include)

find_library(NeoML_NeoML_LIB NAMES NeoML HINTS ENV{NeoML_ROOT} PATH_SUFFIXES ${NeoML_LIB_DIR_SUFFIX})
find_library(NeoML_NeoMathEngine_LIB NAMES NeoMathEngine HINTS ENV{NeoML_ROOT} PATH_SUFFIXES ${NeoML_LIB_DIR_SUFFIX})
find_library(NeoML_NeoMathEngineAvx_LIB NAMES NeoMathEngineAvx HINTS ENV{NeoML_ROOT} PATH_SUFFIXES ${NeoML_LIB_DIR_SUFFIX})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(NeoML DEFAULT_MSG NeoML_INCLUDE_DIR NeoML_NeoML_LIB NeoML_NeoMathEngine_LIB NeoML_NeoMathEngineAvx_LIB)
mark_as_advanced(NeoML_INCLUDE_DIR NeoML_NeoML_LIB NeoML_NeoMathEngine_LIB NeoML_NeoMathEngineAvx_LIB)

# Linking thirdparty libraries
if(NeoML_FOUND)
	target_compile_definitions(${PROJECT_NAME} PUBLIC STEPNN_USE_NEOML)
	target_include_directories(${PROJECT_NAME} PUBLIC ${NeoML_INCLUDE_DIR})
	target_link_libraries(${PROJECT_NAME} PUBLIC ${NeoML_NeoML_LIB})
	target_link_libraries(${PROJECT_NAME} PUBLIC ${NeoML_NeoMathEngine_LIB})
	target_link_libraries(${PROJECT_NAME} PUBLIC ${NeoML_NeoMathEngineAvx_LIB})
endif()