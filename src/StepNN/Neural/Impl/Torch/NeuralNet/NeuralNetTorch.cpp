#include <torch/torch.h>

#include "StepNN/Neural/Data/NeuralConfiguration/OptimizerSettings.h"

#include "StepNN/Neural/Impl/Torch/Interfaces/IUserTorchSequential.h"

#include "StepNN/Neural/Impl/Torch/Dataset/DataLoaderTorch.h"

#include "NeuralNetTorch.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

class NeuralNetTorch::Impl : public IUserTorchSequential
{
public:
	Impl()
	{
	}

	void SetDataLoader(std::unique_ptr<IDataLoaderTorch>&& dataLoader)
	{
		m_dataLoader = std::move(dataLoader);
	}

	void Train()
	{
		const auto& trainSettings = m_config.trainSettings;
		const auto& sampleSettings = m_config.sampleSettings;
		const auto& classificationSettings = m_config.classificationSettings;

		// neural net layer configuration
		auto sequential = GetTorchSequential()->get();
		sequential->train();

		

		//auto dataLoader = torch::data::make_data_loader();

		//auto train_loader =
		//	torch::data::make_data_loader

		float epochLoss;
		for (int epoch = 0; epoch < trainSettings.epochCount; ++epoch)
		{
			epochLoss = 0.0f;

		//	int iterationPerEpoch = 0; //@ todo
		//	for (int iter = 0; iter < iterationPerEpoch; ++iter)
		//	{
		//		sequential->zero_grad();
		//		auto output = sequential->forward(/*@todo add inputs*/);

		//		dataset->GetTrainSamples(iter, trainSettings.trainBatchWidth, dataBlob);
		//		dataset->GetTrainLabels(iter, trainSettings.trainBatchWidth, labelBlob);

		//		dnn.RunAndLearnOnce();
		//		epochLoss += lossLayer->GetLastLoss();

		//	}
		//	LOG(L_INFO, "NeoML: Epoch {}/{} loss: {}", epoch + 1, trainSettings.epochCount, epochLoss / iterationPerEpoch);
		//	dataset->Reshuffle();
		}
		//LOG(L_INFO, "NeoML NeuralNet: End training. Loss: {0}", epochLoss / iterationPerEpoch);

	}

	void Configure(const NeuralConfiguration& config)
	{
		CreateOptimizer(config.optimizerSettings);
	}

private:
	void CreateOptimizer(const OptimizerSettings& optimSettings)
	{
		//m_optimizer = std::make_unique<torch::optim::Adam>();
		//@todo
	}

private:
	std::unique_ptr<torch::optim::Optimizer> m_optimizer;
	NeuralConfiguration m_config;

	std::unique_ptr<IDataLoaderTorch> m_dataLoader;
};

//.............................................................................

NeuralNetTorch::NeuralNetTorch(const ILayerEngine* layerEngine)
	: BaseNeuralNet(layerEngine)
	, m_impl(new Impl())
{}

//.............................................................................

NeuralNetTorch::~NeuralNetTorch() = default;

//.............................................................................

void NeuralNetTorch::Train()
{
	auto* dataset = GetDatasetImpl();
	m_impl->SetDataLoader(IDataLoaderTorch::Create(std::move(*dataset), torch::data::DataLoaderOptions()));
	m_impl->Train();
}

}