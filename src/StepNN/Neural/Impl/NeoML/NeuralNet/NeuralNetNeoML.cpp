#include "NeoML/Dnn/Layers/SourceLayer.h"
#include "NeoML/Dnn/Layers/LossLayer.h"

#include "StepNN/Utils/Logging/Logging.h"

#include "StepNN/Neural/Data/NeuralConfiguration/BlobDataType.h"
#include "StepNN/Neural/Interfaces/DefaultLayerID.h"
#include "StepNN/Neural/Impl/NeoML/CommonNeoML.h"
#include "StepNN/Neural/Impl/NeoML/Layers/BaseLayerNeoML.h"

#include "NeuralNetNeoML.h"

using namespace StepNN::Neural::Interfaces;

namespace {

NeoML::TBlobType GetBlobType(StepNN::Neural::BlobDataType type)
{
	switch (type)
	{
	case StepNN::Neural::BlobDataType::Int:
		return NeoML::CT_Int;
	case StepNN::Neural::BlobDataType::Float:
		return NeoML::CT_Float;
	default:
		return NeoML::CT_Invalid;
	}
}

}

namespace StepNN::Neural {

NeuralNetNeoML::NeuralNetNeoML(const ILayerEngine* layerEngine)
	: BaseNeuralNet(layerEngine)
{}

//.............................................................................

NeuralNetNeoML::~NeuralNetNeoML() = default;

//.............................................................................

void NeuralNetNeoML::Train()
{
	NeoMathEngineRef mathEngineRef = *GetMathEngine().get();

	NeoML::CRandom random(0x123);
	NeoML::CDnn dnn(random, mathEngineRef);
	LOG(L_INFO, "NeoML NeuralNet: dnn created");

	Configure(dnn);
	LOG(L_INFO, "NeoML NeuralNet: dnn configured");

	auto* dataset = GetDatasetImpl();
	assert(dataset);

	auto dataBlob = dataset->GetDataBlob();
	auto labelBlob = dataset->GetLabelBlob();

	const auto& trainSettings = m_config.trainSettings;
	const auto& sampleSettings = m_config.sampleSettings;
	const auto& classificationSettings = m_config.classificationSettings;

	dataBlob = NeoML::CDnnBlob::Create2DImageBlob(mathEngineRef, GetBlobType(m_config.blobDataType), trainSettings.trainBatchLength, trainSettings.trainBatchWidth,
		sampleSettings.sampleHeight, sampleSettings.sampleWidth, sampleSettings.channelsCount);
	labelBlob = NeoML::CDnnBlob::CreateDataBlob(mathEngineRef, GetBlobType(m_config.blobDataType), trainSettings.trainBatchLength, trainSettings.trainBatchWidth, classificationSettings.outputDimension);

	CheckCast<NeoML::CSourceLayer>(dnn.GetLayer(DefaultLayerID::SOURCE_LAYER_ID.data()))->SetBlob(dataBlob);
	CheckCast<NeoML::CSourceLayer>(dnn.GetLayer(DefaultLayerID::LABEL_LAYER_ID.data()))->SetBlob(labelBlob);

	auto lossLayer = CheckCast<NeoML::CLossLayer>(dnn.GetLayer(DefaultLayerID::LOSS_LAYER_ID.data()));

	int iterationPerEpoch = static_cast<int>(dataset->GetTrainSize() / trainSettings.trainBatchWidth);
	assert(dataset->GetTrainSize() % trainSettings.trainBatchWidth == 0);

	LOG(L_INFO, "NeoML NeuralNet: Start training");
	float epochLoss;
	for (int epoch = 0; epoch < trainSettings.epochCount; ++epoch)
	{
		epochLoss = 0.0f;
		for (int iter = 0; iter < iterationPerEpoch; ++iter)
		{
			dataset->GetTrainSamples(iter, trainSettings.trainBatchWidth, dataBlob);
			dataset->GetTrainLabels(iter, trainSettings.trainBatchWidth, labelBlob);

			dnn.RunAndLearnOnce();
			epochLoss += lossLayer->GetLastLoss();
			
		}
		LOG(L_INFO, "NeoML: Epoch {}/{} loss: {}", epoch+1, trainSettings.epochCount, epochLoss / iterationPerEpoch);
		dataset->Reshuffle();
	}
	LOG(L_INFO, "NeoML NeuralNet: End training. Loss: {0}", epochLoss / iterationPerEpoch);

	LOG(L_INFO, "NeoML NeuralNet: Begin evaluate testing data");
	int testIterations = static_cast<int>(dataset->GetTestSize() / trainSettings.testBatchWidth);
	assert(dataset->GetTestSize() % trainSettings.testBatchWidth == 0);
	float testDataLoss = 0.0f;
	for (int iter = 0; iter < testIterations; ++iter)
	{
		dataset->GetTestSamples(iter, trainSettings.testBatchWidth, dataBlob);
		dataset->GetTestLabels(iter, trainSettings.testBatchWidth, labelBlob);
		dnn.RunOnce();
		testDataLoss += lossLayer->GetLastLoss();
	}
	testDataLoss /= trainSettings.testBatchWidth;
	LOG(L_INFO, "NeoML NeuralNet: End evaluate testing data. Loss: {0}", testDataLoss);
}

//.............................................................................

void NeuralNetNeoML::Configure(NeoML::CDnn& dnn)
{
	for (const auto& layer : m_layerEnginePtr->GetLayers())
		dnn.AddLayer(*CastLayer(layer.get())->GetLayerImpl());
}

//.............................................................................

BaseLayerNeoML* NeuralNetNeoML::CastLayer(ILayer* layer)
{
	BaseLayerNeoML* layerNeoML = dynamic_cast<BaseLayerNeoML*>(layer);
	assert(layerNeoML);
	return layerNeoML;
}

}