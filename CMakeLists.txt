cmake_minimum_required(VERSION 3.14)

project(StepNN LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
	src/Types/CommonDefs.h
	src/Utils/Algorithms/FindPair.h
	src/Utils/Containers/Graph.h
	src/Neural/Data/LayerType.h
	src/Neural/Data/NeuralFrameworkType.h
	src/Neural/Interfaces/ILayer.h
	src/Neural/Interfaces/ILayerGraph.h
	src/Neural/Interfaces/ILayerFactory.h
	src/Neural/Interfaces/ILayerEngine.h
	src/Neural/Interfaces/INeuralEngine.h
	src/Neural/Interfaces/INeuralNet.h
	src/Neural/Layer/Settings/BaseLayerSettings.h
	src/Neural/Layer/Settings/ConvLayerSettings.h
	src/Neural/Layer/Settings/Stub.cpp
	src/Neural/Layer/Graph/LayerGraph.h
	src/Neural/Layer/Graph/LayerGraph.cpp
	src/Neural/Layer/Engine/BaseLayerEngine.h
	src/Neural/Layer/Engine/BaseLayerEngine.cpp
	src/Neural/NeuralEngines/NeuralEngine.h
	src/Neural/NeuralEngines/NeuralEngine.cpp

	src/Neural/NeuralEngines/NeuralEngineDummy/NeuralEngineDummy.h
	src/Neural/NeuralEngines/NeuralEngineDummy/NeuralEngineDummy.cpp

	src/Neural/NeuralEngines/NeuralEngineNeoML/NeuralNet/NeuralNetNeoML.h
	src/Neural/NeuralEngines/NeuralEngineNeoML/NeuralNet/NeuralNetNeoML.cpp
	src/Neural/NeuralEngines/NeuralEngineNeoML/Layers/BaseLayerNeoML.h
	src/Neural/NeuralEngines/NeuralEngineNeoML/Layers/ConvLayerNeoML.cpp
	src/Neural/NeuralEngines/NeuralEngineNeoML/LayerEngine/LayerEngineNeoML.h
	src/Neural/NeuralEngines/NeuralEngineNeoML/LayerEngine/LayerEngineNeoML.cpp
	src/Neural/NeuralEngines/NeuralEngineNeoML/LayerEngine/LayerEngineNeoML.LayerFactory.cpp
	src/Neural/NeuralEngines/NeuralEngineNeoML/NeuralEngineNeoML.h
	src/Neural/NeuralEngines/NeuralEngineNeoML/NeuralEngineNeoML.cpp

	src/Neural/NeuralEngines/NeuralEngineTF/NeuralNet/NeuralNetTF.h
	src/Neural/NeuralEngines/NeuralEngineTF/NeuralNet/NeuralNetTF.cpp
	src/Neural/NeuralEngines/NeuralEngineTF/Layers/BaseLayerTF.h
	src/Neural/NeuralEngines/NeuralEngineTF/Layers/ConvLayerTF.cpp
	src/Neural/NeuralEngines/NeuralEngineTF/LayerEngine/LayerEngineTF.h
	src/Neural/NeuralEngines/NeuralEngineTF/LayerEngine/LayerEngineTF.cpp
	src/Neural/NeuralEngines/NeuralEngineTF/LayerEngine/LayerEngineTF.LayerFactory.cpp
	src/Neural/NeuralEngines/NeuralEngineTF/NeuralEngineTF.h
	src/Neural/NeuralEngines/NeuralEngineTF/NeuralEngineTF.cpp

	src/Neural/NeuralEngines/NeuralEngineTorch/NeuralNet/NeuralNetTorch.h
	src/Neural/NeuralEngines/NeuralEngineTorch/NeuralNet/NeuralNetTorch.cpp
	src/Neural/NeuralEngines/NeuralEngineTorch/Layers/BaseLayerTorch.h
	src/Neural/NeuralEngines/NeuralEngineTorch/Layers/ConvLayerTorch.cpp
	src/Neural/NeuralEngines/NeuralEngineTorch/LayerEngine/LayerEngineTorch.h
	src/Neural/NeuralEngines/NeuralEngineTorch/LayerEngine/LayerEngineTorch.cpp
	src/Neural/NeuralEngines/NeuralEngineTorch/LayerEngine/LayerEngineTorch.LayerFactory.cpp
	src/Neural/NeuralEngines/NeuralEngineTorch/NeuralEngineTorch.h
	src/Neural/NeuralEngines/NeuralEngineTorch/NeuralEngineTorch.cpp

	src/main.cpp
)

add_executable(StepNN ${PROJECT_SOURCES})