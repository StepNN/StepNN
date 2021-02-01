set(STEPNN_LIB_TYPE shared_lib)
if(NOT StepNN_BUILD_SHARED)
	set(STEPNN_LIB_TYPE static_lib)
endif()

AddTarget(NAME StepNN
	TYPE
		${STEPNN_LIB_TYPE}
	SOURCE_DIR
		${SRC_ROOT}/
	SRC
		*.cpp
		*.h
	SUBDIRS
		StepNN/Types
		StepNN/Utils
		StepNN/Utils/Algoritms
		StepNN/Utils/Containers
		StepNN/Utils/Templates
		StepNN/Neural
		StepNN/Neural/Data
		StepNN/Neural/Engine
		StepNN/Neural/Impl
		StepNN/Neural/Impl/Dummy
		StepNN/Neural/Impl/NeoML
		StepNN/Neural/Impl/NeoML/Dataset
		StepNN/Neural/Impl/NeoML/Interfaces
		StepNN/Neural/Impl/NeoML/LayerEngine
		StepNN/Neural/Impl/NeoML/Layers
		StepNN/Neural/Impl/NeoML/NeuralEngine
		StepNN/Neural/Impl/NeoML/NeuralNet
		StepNN/Neural/Impl/TF
		StepNN/Neural/Impl/TF/LayerEngine
		StepNN/Neural/Impl/TF/Layers
		StepNN/Neural/Impl/TF/NeuralEngine
		StepNN/Neural/Impl/TF/NeuralNet
		StepNN/Neural/Impl/Torch
		StepNN/Neural/Impl/Torch/LayerEngine
		StepNN/Neural/Impl/Torch/Layers
		StepNN/Neural/Impl/Torch/NeuralEngine
		StepNN/Neural/Impl/Torch/NeuralNet
		StepNN/Neural/Interfaces
		StepNN/Neural/Layer
		StepNN/Neural/Layer/Settings
)
