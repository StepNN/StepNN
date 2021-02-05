if(NOT StepNN_USE_TORCH)
	return()
endif()

if (${CMAKE_BUILD_TYPE} MATCHES "Debug")
	set(PATH_SUFFIX "_debug")
else()
	set(PATH_SUFFIX "_release")
endif()

set(torch_CONFIG_PATH "C:/Projects/SDK/libtorch/libtorch${PATH_SUFFIX}/share/cmake/Torch/TorchConfig.cmake")
include(${torch_CONFIG_PATH})

target_compile_definitions(${PROJECT_NAME} PUBLIC STEPNN_USE_TORCH)
target_include_directories(${PROJECT_NAME} PUBLIC ${TORCH_INCLUDE_DIRS})
# TORCH_LIBRARIES already linked to ${PROJECT_NAME}
