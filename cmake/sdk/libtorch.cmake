if(NOT StepNN_USE_TORCH)
	return()
endif()

if (${CMAKE_BUILD_TYPE} MATCHES "Debug")
	set(PATH_SUFFIX "_debug")
else()
	set(PATH_SUFFIX "_release")
endif()

set(TORCH_ROOT "C:/Projects/SDK/libtorch/libtorch${PATH_SUFFIX}")
set(TORCH_INCLUDE_DIR
	"${TORCH_ROOT}/include"
	"${TORCH_ROOT}/include/torch/csrc/api/include"
	)

set(TORCH_LIBRARIES
	"${TORCH_ROOT}/lib/asmjit.lib"
	"${TORCH_ROOT}/lib/c10.lib"
	"${TORCH_ROOT}/lib/c10_cuda.lib"
	"${TORCH_ROOT}/lib/c10d.lib"
	"${TORCH_ROOT}/lib/caffe2_detectron_ops_gpu.lib"
	"${TORCH_ROOT}/lib/caffe2_module_test_dynamic.lib"
	"${TORCH_ROOT}/lib/caffe2_nvrtc.lib"
	"${TORCH_ROOT}/lib/clog.lib"
	"${TORCH_ROOT}/lib/cpuinfo.lib"
	"${TORCH_ROOT}/lib/dnnl.lib"
	"${TORCH_ROOT}/lib/fbgemm.lib"
	"${TORCH_ROOT}/lib/gloo.lib"
	"${TORCH_ROOT}/lib/gloo_cuda.lib"
	"${TORCH_ROOT}/lib/libprotobufd.lib"
	"${TORCH_ROOT}/lib/libprotobuf-lited.lib"
	"${TORCH_ROOT}/lib/libprotocd.lib"
	"${TORCH_ROOT}/lib/mkldnn.lib"
	"${TORCH_ROOT}/lib/torch.lib"
	"${TORCH_ROOT}/lib/torch_cpu.lib"
	"${TORCH_ROOT}/lib/torch_cuda.lib"
	)

target_compile_definitions(${PROJECT_NAME} PUBLIC STEPNN_USE_TORCH)
target_include_directories(${PROJECT_NAME} PUBLIC ${TORCH_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC ${TORCH_LIBRARIES})

# TORCH_LIBRARIES already linked to ${PROJECT_NAME}
