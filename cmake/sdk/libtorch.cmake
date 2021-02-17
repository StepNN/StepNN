if(NOT StepNN_USE_TORCH)
	return()
endif()

if (${CMAKE_BUILD_TYPE} MATCHES "Debug")
	set(PATH_SUFFIX "_debug")
else()
	set(PATH_SUFFIX "_release")
endif()

set(TORCH_ROOT "C:/Projects/SDK/libtorch/libtorch${PATH_SUFFIX}")
set(TORCH_CMAKE_PATH "${TORCH_ROOT}/share/cmake")
list(APPEND CMAKE_PREFIX_PATH "${TORCH_CMAKE_PATH}")
find_package(Torch REQUIRED)

target_compile_definitions(${PROJECT_NAME} PUBLIC STEPNN_USE_TORCH)
target_include_directories(${PROJECT_NAME} PUBLIC ${TORCH_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC ${TORCH_LIBRARIES})