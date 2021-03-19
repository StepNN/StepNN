#include "DatasetMNIST_Torch.h"

#include "Datasets/MNIST/Decoder/mnist_reader.hpp"

namespace StepNN::Dataset {

class DatasetMNIST_TorchImpl : public Neural::DatasetTorchImpl
{
public:
	explicit DatasetMNIST_TorchImpl(std::vector<std::vector<uint8_t>>& data, std::vector<uint8_t>& labels)
	{
		Init(data, labels);
	}

	torch::data::Example<> get(size_t index) override { return { m_samples[index], m_labels[index] }; }
	c10::optional<size_t> size() const override { return m_samples.size(); }

	c10::ScalarType GetSampleScalarType() const override { return torch::kByte; }
	c10::ScalarType GetLabelScalarType() const override { return torch::kByte; }

private:
	void Init(std::vector<std::vector<uint8_t>>& data, std::vector<uint8_t>& labels)
	{
		m_samples.reserve(data.size());
		m_labels.reserve(data.size());
		for (size_t i = 0; i < data.size(); ++i)
		{
			m_samples.push_back(torch::from_blob(data[i].data(), { 28, 28, 1 }, torch::kByte));
			m_labels.push_back(torch::tensor(labels[i]));
			//m_labels.push_back(torch::from_blob(&labels[i], { 1, 1, 1 }, torch::kByte));
		}
	}

private:
	std::vector<torch::Tensor> m_samples, m_labels;
};

//.............................................................................

void DatasetMNIST_Torch::Open(const std::string& filename)
{
	auto dataset = mnist::read_dataset<std::vector, std::vector, uint8_t, uint8_t>(filename.data());
	m_trainDataset = std::make_unique<DatasetMNIST_TorchImpl>(dataset.training_images, dataset.training_labels);
	m_testDataset = std::make_unique<DatasetMNIST_TorchImpl>(dataset.test_images, dataset.test_labels);
}

//.............................................................................

size_t DatasetMNIST_Torch::GetTrainSize() const
{
	return m_trainDataset->size().value();
}

//.............................................................................

size_t DatasetMNIST_Torch::GetTestSize() const
{
	return m_testDataset->size().value();
}

}