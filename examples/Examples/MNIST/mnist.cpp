#include "DatasetPathes.h"

#include "Datasets/MNIST/DatasetMNIST.h"

#include "StepNN/Utils/Logging/Logging.h"

#include "StepNN/Neural/Engine/NeuralEngine.h"

#include "StepNN/Neural/Layer/Settings/BatchNormalizationLayerSettings.h"
#include "StepNN/Neural/Layer/Settings/ConvLayerSettings.h"
#include "StepNN/Neural/Layer/Settings/CrossEntropyLayerSettings.h"
#include "StepNN/Neural/Layer/Settings/DenseLayerSettings.h"
#include "StepNN/Neural/Layer/Settings/FlattenLayerSettings.h"
#include "StepNN/Neural/Layer/Settings/MaxPoolingLayerSettings.h"
#include "StepNN/Neural/Layer/Settings/OutputLayerSettings.h"
#include "StepNN/Neural/Layer/Settings/ReLULayerSettings.h"
#include "StepNN/Neural/Layer/Settings/SourceLayerSettings.h"

#include "StepNN/Neural/Interfaces/DefaultLayerID.h"

using namespace StepNN;
using namespace StepNN::Neural;
using namespace StepNN::Neural::Interfaces;
using namespace StepNN::Dataset;

NeuralConfiguration GetNeuralConfiguration()
{
	NeuralConfiguration config;

	config.sampleSettings.sampleWidth = 28;
	config.sampleSettings.sampleHeight = 28;
	config.sampleSettings.channelsCount = 1;

	config.trainSettings.trainBatchWidth = 100;
	config.trainSettings.testBatchWidth = 100;
	config.trainSettings.epochCount = 15;

	config.classificationSettings.outputDimension = 10;

	config.memoryLimit = 0;
	config.deviceType = DeviceType::CPU;
	config.blobDataType = BlobDataType::Float;

	return config;
}

void ConfigureNet(ILayerEngine& layerEngine)
{
	/*{
		auto conv = ConvLayerSettings("Conv1");
		conv.SetKernel(3, 3);
		conv.SetOutChannels(64);
		layerEngine.AddLayer(conv);
	}
	{
		auto conv = ConvLayerSettings("Conv2");
		conv.SetKernel(3, 3);
		conv.SetOutChannels(64);
		layerEngine.AddLayer(conv);
	}
	{
		auto conv = ConvLayerSettings("Conv3");
		conv.SetKernel(3, 3);
		conv.SetOutChannels(128);
		layerEngine.AddLayer(conv);
	}
	{
		auto conv = ConvLayerSettings("Conv4");
		conv.SetKernel(3, 3);
		conv.SetOutChannels(128);
		layerEngine.AddLayer(conv);
	}
	{
		auto conv = ConvLayerSettings("Conv5");
		conv.SetKernel(3, 3);
		conv.SetOutChannels(256);
		layerEngine.AddLayer(conv);
	}
	{
		auto maxPool = MaxPoolingLayerSettings("MaxPool1");
		maxPool.SetKernel(2, 2);
		layerEngine.AddLayer(maxPool);
	}
	{
		auto maxPool = MaxPoolingLayerSettings("MaxPool2");
		maxPool.SetKernel(2, 2);
		layerEngine.AddLayer(maxPool);
	}
	{
		auto maxPool = MaxPoolingLayerSettings("MaxPool3");
		maxPool.SetKernel(2, 2);
		layerEngine.AddLayer(maxPool);
	}
	{
		auto dense = DenseLayerSettings("Dense1");
		dense.SetDenseSize(512);
		layerEngine.AddLayer(dense);
	}
	{
		auto dense = DenseLayerSettings("Dense2");
		dense.SetDenseSize(10);
		layerEngine.AddLayer(dense);
	}

	layerEngine.AddLayer(ReLULayerSettings("Relu1"));
	layerEngine.AddLayer(ReLULayerSettings("Relu2"));
	layerEngine.AddLayer(ReLULayerSettings("Relu3"));
	layerEngine.AddLayer(ReLULayerSettings("Relu4"));
	layerEngine.AddLayer(ReLULayerSettings("Relu5"));
	layerEngine.AddLayer(ReLULayerSettings("Relu6"));
	layerEngine.AddLayer(BatchNormalizationLayerSettings("BatchNorm1"));
	layerEngine.AddLayer(BatchNormalizationLayerSettings("BatchNorm2"));
	layerEngine.AddLayer(BatchNormalizationLayerSettings("BatchNorm3"));
	layerEngine.AddLayer(FlattenLayerSettings("Flatten1"));
	layerEngine.AddLayer(SourceLayerSettings(DefaultLayerID::SOURCE_LAYER_ID));
	layerEngine.AddLayer(SourceLayerSettings(DefaultLayerID::LABEL_LAYER_ID));
	layerEngine.AddLayer(CrossEntropyLayerSettings(DefaultLayerID::LOSS_LAYER_ID));

	layerEngine.SequentialConnection({
		DefaultLayerID::SOURCE_LAYER_ID
		, "Conv1"
		, "Relu1"
		, "Conv2"
		, "Relu2"
		, "MaxPool1"
		, "BatchNorm1"
		, "Conv3"
		, "Relu3"
		, "Conv4"
		, "Relu4"
		, "MaxPool2"
		, "BatchNorm2"
		, "Conv5"
		, "Relu5"
		, "MaxPool3"
		, "Flatten1"
		, "BatchNorm3"
		, "Dense1"
		, "Relu6"
		, "Dense2"
		, DefaultLayerID::LOSS_LAYER_ID
	});

	layerEngine.ConnectLayers(DefaultLayerID::LOSS_LAYER_ID, DefaultLayerID::LABEL_LAYER_ID);*/
}

/*
* Example from NeoML github:
* https://github.com/neoml-lib/neoml/blob/master/NeoML/docs/en/Tutorial/SimpleNet.md
*/
void ConfigureNeoMLExampleNet(ILayerEngine& layerEngine)
{
	/*{
		auto dense = DenseLayerSettings("Dense1");
		dense.SetDenseSize(1024);
		layerEngine.AddLayer(dense);
	}
	{
		auto dense = DenseLayerSettings("Dense2");
		dense.SetDenseSize(512);
		layerEngine.AddLayer(dense);
	}
	{
		auto dense = DenseLayerSettings("Dense3");
		dense.SetDenseSize(10);
		layerEngine.AddLayer(dense);
	}
	layerEngine.AddLayer(ReLULayerSettings("Relu1"));
	layerEngine.AddLayer(ReLULayerSettings("Relu2"));
	layerEngine.AddLayer(SourceLayerSettings(DefaultLayerID::SOURCE_LAYER_ID));
	layerEngine.AddLayer(SourceLayerSettings(DefaultLayerID::LABEL_LAYER_ID));
	layerEngine.AddLayer(CrossEntropyLayerSettings(DefaultLayerID::LOSS_LAYER_ID));

	layerEngine.SequentialConnection({
		DefaultLayerID::SOURCE_LAYER_ID
		, "Dense1"
		, "Relu1"
		, "Dense2"
		, "Relu2"
		, "Dense3"
		, DefaultLayerID::LOSS_LAYER_ID
	});
	layerEngine.ConnectLayers(DefaultLayerID::LOSS_LAYER_ID, DefaultLayerID::LABEL_LAYER_ID);*/
}

#ifdef STEPNN_USE_NEOML
void ExampleNeoML()
{
	const auto neuralFrameworkType = NeuralFrameworkType::NeoML;

	auto neuralEngine = std::make_unique<NeuralEngine>(neuralFrameworkType);

	neuralEngine->GetDatasetController().SetDataset(CreateDatasetMNIST(neuralFrameworkType));
	neuralEngine->GetDatasetController().GetDataset()->Open(MNIST_PATH);
	neuralEngine->GetConfigurator().SetNeuralConfiguration(GetNeuralConfiguration());

	auto& layerEngine = neuralEngine->GetLayerEngine();
	//ConfigureNet(layerEngine);
	ConfigureNeoMLExampleNet(layerEngine);

	neuralEngine->GetTrainable().Train();
}
#endif

void ConfigureLogger()
{
	Logging::LoggingSettings logSettings;
	Logging::LoggingSettings::LogInfos logInfos = {
		{ Logging::LOGGING_CONSOLE_STR, Logging::LoggingOutputMode::Console, L_INFO },
	};
	logSettings.SetLogInfos(std::move(logInfos));
	logSettings.SetSyncMode(Logging::LoggingSyncMode::Async);
	logSettings.SetLogDirectory("C:/Projects/StepNN/StepNN/out/StepNN_Logs");
	logSettings.SetBacktraceSize(30);

	LOGGER.SetLoggingSettings(std::move(logSettings));
}

int main(int argc, char* argv[])
{
	ConfigureLogger();

#ifdef STEPNN_USE_NEOML
	ExampleNeoML();
#endif

	return 0;
}