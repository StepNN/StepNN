if(NOT StepNN_BUILD_EXAMPLES)
	return()
endif()

include(${EXAMPLES_ROOT}/Examples/MNIST/MNIST.cmake)
include(${EXAMPLES_ROOT}/Examples/Logging/Logging.cmake)