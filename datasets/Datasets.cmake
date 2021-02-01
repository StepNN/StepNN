if(NOT StepNN_BUILD_DATASETS)
	return()
endif()

#todo Make as string variable
set(DATASET_MNIST_PATH "C:/Projects/StepNN/StepNN-datasets")

configure_file(${CMAKE_HELPERS_DIR}/DatasetPathes.h.in DatasetPathes.h @ONLY)

AddTarget(NAME Datasets
	TYPE
		${STEPNN_LIB_TYPE}
	SOURCE_DIR
		${DATASETS_ROOT}/
	SRC
		*.cpp
		*.h
	SUBDIRS
		Datasets/MNIST
		Datasets/MNIST/Decoder
	DEPENDENCIES
		StepNN
)