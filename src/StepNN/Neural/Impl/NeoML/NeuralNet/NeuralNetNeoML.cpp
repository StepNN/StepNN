#include "StepNN/Neural/Impl/NeoML/CommonNeoML.h"
#include "NeoML/Dnn/Layers/SourceLayer.h"
#include "NeoML/Dnn/Layers/LossLayer.h"

#include "StepNN/Neural/Data/BlobDataType.h"
#include "StepNN/Neural/Interfaces/DefaultLayerID.h"
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

NeuralNetNeoML::NeuralNetNeoML(const ILayerEngine* layerEngine, NeoMathEnginePtr mathEngine)
	: BaseNeuralNet(layerEngine)
	, m_mathEngine(mathEngine)
{}

//.............................................................................

NeuralNetNeoML::~NeuralNetNeoML() = default;

//.............................................................................

void NeuralNetNeoML::Configure()
{

}

//.............................................................................

void NeuralNetNeoML::ProcessTrain()
{
	assert(m_mathEngine);
	NeoMathEngineRef mathEngineRef = *m_mathEngine;

	NeoML::CRandom random(0x123);
	NeoML::CDnn dnn(random, mathEngineRef);
	Configure(dnn);

	auto* dataset = GetDatasetImpl();
	assert(dataset);

	auto& dataBlob = dataset->GetDataBlob();
	auto& labelBlob = dataset->GetLabelBlob();

	dataBlob = NeoML::CDnnBlob::Create2DImageBlob(mathEngineRef, GetBlobType(m_config.blobDataType), m_config.trainBatchLength, m_config.trainBatchWidth,
		m_config.sampleHeight, m_config.sampleWidth, m_config.channelsCount);
	labelBlob = NeoML::CDnnBlob::CreateDataBlob(mathEngineRef, GetBlobType(m_config.blobDataType), m_config.trainBatchLength, m_config.trainBatchWidth, m_config.channelsCount);

	CheckCast<NeoML::CSourceLayer>(dnn.GetLayer(DefaultLayerID::SOURCE_LAYER_ID.data()))->SetBlob(dataBlob);
	CheckCast<NeoML::CSourceLayer>(dnn.GetLayer(DefaultLayerID::LABEL_LAYER_ID.data()))->SetBlob(labelBlob);

	auto lossLayer = CheckCast<NeoML::CLossLayer>(dnn.GetLayer(DefaultLayerID::LOSS_LAYER_ID.data()));

	int iterationPerEpoch = static_cast<int>(dataset->GetTrainSize() / m_config.trainBatchWidth);
	assert(dataset->GetTrainSize() % m_config.trainBatchWidth == 0);
	 
	for (int epoch = 0; epoch < m_config.epochCount; ++epoch)
	{
		float epochLoss = 0.0f;
		for (int iter = 0; iter < iterationPerEpoch; ++iter)
		{
			dataset->GetTrainSamples(iter, m_config.trainBatchWidth, dataBlob);
			dataset->GetTrainLabels(iter, m_config.trainBatchWidth, labelBlob);

			dnn.RunAndLearnOnce();
			epochLoss += lossLayer->GetLastLoss();
		}
		dataset->Reshuffle();
	}

	int testIterations = static_cast<int>(dataset->GetTestSize() / m_config.testBatchWidth);
	assert(dataset->GetTestSize() % m_config.testBatchWidth == 0);
	float testDataLoss = 0.0f;
	for (int iter = 0; iter < testIterations; ++iter)
	{
		dataset->GetTestSamples(iter, m_config.testBatchWidth, dataBlob);
		dataset->GetTestLabels(iter, m_config.testBatchWidth, labelBlob);
		dnn.RunOnce();
		testDataLoss += lossLayer->GetLastLoss();
	}
	testDataLoss /= m_config.testBatchWidth;
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