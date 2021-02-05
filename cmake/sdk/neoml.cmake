if(NOT StepNN_USE_NEOML)
	return()
endif()

set(NeoML_ROOT "C:/Projects/SDK/NeoML")

if (${CMAKE_BUILD_TYPE} MATCHES "Debug")
	set(NeoML_LIB_DIR_SUFFIX "lib/debug")
else()
	set(NeoML_LIB_DIR_SUFFIX "lib/release")
endif()

find_path(NeoML_INCLUDE_DIR NAMES NeoML/NeoML.h NeoMathEngine/NeoMathEngine.h HINTS ${NeoML_ROOT} PATH_SUFFIXES include)

find_library(NeoML_NeoML_LIB NAMES NeoML HINTS ${NeoML_ROOT} PATH_SUFFIXES ${NeoML_LIB_DIR_SUFFIX})
find_library(NeoML_NeoMathEngine_LIB NAMES NeoMathEngine HINTS ${NeoML_ROOT} PATH_SUFFIXES ${NeoML_LIB_DIR_SUFFIX})
find_library(NeoML_NeoMathEngineAvx_LIB NAMES NeoMathEngineAvx HINTS ${NeoML_ROOT} PATH_SUFFIXES ${NeoML_LIB_DIR_SUFFIX})

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