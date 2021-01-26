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
		StepNN/Neural
		StepNN/Neural/Data
		StepNN/Neural/Interfaces
		StepNN/Neural/Layer
		StepNN/Neural/Layer/Engine
		StepNN/Neural/Layer/Graph
		StepNN/Neural/Layer/Settings
		StepNN/Neural/NeuralEngines
		StepNN/Neural/NeuralEngines/NeuralEngineDummy
		StepNN/Neural/NeuralEngines/NeuralEngineNeoML
		StepNN/Neural/NeuralEngines/NeuralEngineNeoML/LayerEngine
		StepNN/Neural/NeuralEngines/NeuralEngineNeoML/Layers
		StepNN/Neural/NeuralEngines/NeuralEngineNeoML/NeuralNet
		StepNN/Neural/NeuralEngines/NeuralEngineTF
		StepNN/Neural/NeuralEngines/NeuralEngineTF/LayerEngine
		StepNN/Neural/NeuralEngines/NeuralEngineTF/Layers
		StepNN/Neural/NeuralEngines/NeuralEngineTF/NeuralNet
		StepNN/Neural/NeuralEngines/NeuralEngineTorch
		StepNN/Neural/NeuralEngines/NeuralEngineTorch/LayerEngine
		StepNN/Neural/NeuralEngines/NeuralEngineTorch/Layers
		StepNN/Neural/NeuralEngines/NeuralEngineTorch/NeuralNet
)
