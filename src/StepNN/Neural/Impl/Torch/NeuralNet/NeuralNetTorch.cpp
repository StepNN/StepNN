#include "StepNN/Neural/Data/NeuralConfiguration/OptimizerSettings.h"

#include "StepNN/Neural/Impl/Torch/Dataset/DataLoaderTorch.h"

#include "NeuralNetTorch.h"

#include "StepNN/Utils/Logging/Logging.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

namespace {

std::unique_ptr<torch::optim::Optimizer> CreateOptimizer(const OptimizerSettings& settings, const std::vector<torch::Tensor>& trainableParams)
{
	switch (settings.type)
	{
	case OptimizerType::Adam:
		{
			const auto & adamSettings = dynamic_cast<const AdamSettings&>(settings);
			torch::optim::AdamOptions options;
			
			options
				.lr(adamSettings.lr)
				.eps(adamSettings.eps)
				.weight_decay(adamSettings.weight_decay)
				.betas(std::tuple<double, double>(adamSettings.beta1, adamSettings.beta2))
				.amsgrad(adamSettings.amsgrad)
				;

			return std::make_unique<torch::optim::Adam>(trainableParams, options);
		}
	default:
		return nullptr;
	}
}

}

//.............................................................................

NeuralNetTorch::NeuralNetTorch(const ILayerEngine* layerEngine)
	: BaseNeuralNet(layerEngine)
	, m_device(torch::kCPU)
{}

//.............................................................................

NeuralNetTorch::~NeuralNetTorch() = default;

//.............................................................................

void NeuralNetTorch::Train()
{
	const auto& trainSettings = m_config.trainSettings;
	const auto& sampleSettings = m_config.sampleSettings;
	const auto& classificationSettings = m_config.classificationSettings;

	auto* dataset = GetDatasetImpl();
	auto trainDataLoader = dataset->GetTrainDataLoader();

	/*
	* Optimizer must be created here (instead of OnSetNeuralConfiguration)
	* because it require full configured sequential module
	*/
	m_optimizer = CreateOptimizer(m_config.optimizerSettings, GetTrainableParams());

	auto net = GetTorchSequential()->get();
	net->to(m_device);

	auto lossCriterion = GetLossCriterion();

	for (int epoch = 0; epoch < trainSettings.epochCount; ++epoch)
	{
		float epochLoss = 0.0f;
		int iter = 0;

		net->train();

		for(auto& batchData : *trainDataLoader)
		{
			auto data = batchData.data;
			auto targets = batchData.target;

			data = data.to(trainDataLoader->GetSampleScalarType());
			targets = targets.to(trainDataLoader->GetLabelScalarType());

			data.to(m_device);
			targets.to(m_device);

			m_optimizer->zero_grad();
			auto output = net->forward(data);

			auto loss = lossCriterion->CalculateLoss(output, targets);
			epochLoss += loss.item<float>();

			loss.backward();
			m_optimizer->step();

			++iter;
		}

		LOG(L_INFO, "Torch: Epoch {}/{} loss: {}", epoch + 1, trainSettings.epochCount, epochLoss / iter);
	}
}

//.............................................................................

void NeuralNetTorch::Evaluate()
{

}


}