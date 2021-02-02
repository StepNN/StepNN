#include <algorithm>
#include <numeric>

#include "StepNN/Types/CommonDefs.h"

#include "DatasetMNIST_NeoML.h"

namespace StepNN::Dataset {

DatasetMNIST_NeoML::DatasetMNIST_NeoML()
	: m_dataset(nullptr)
{}

//.............................................................................

DatasetMNIST_NeoML::~DatasetMNIST_NeoML() = default;

//.............................................................................

void DatasetMNIST_NeoML::Open(const std::string& filename)
{
	m_dataset = std::make_unique<DatasetImpl>(mnist::read_dataset<std::vector, std::vector, uint8_t, uint8_t>(filename.data()));

	m_shuffleIndicies.reserve(GetTrainSize());
	m_shuffleIndicies.resize(GetTrainSize());
	std::iota(m_shuffleIndicies.begin(), m_shuffleIndicies.end(), 0);
	Reshuffle();
}

//.............................................................................

size_t DatasetMNIST_NeoML::GetTrainSize() const
{
	return m_dataset ? m_dataset->training_images.size() : Defs::INVALID_VALUE_SIZE_T;
}

//.............................................................................

size_t DatasetMNIST_NeoML::GetTestSize() const
{
	return m_dataset ? m_dataset->test_images.size() : Defs::INVALID_VALUE_SIZE_T;
}

//.............................................................................

void DatasetMNIST_NeoML::GetTrainSamples(int iter, int batchSize, FObj::CPtr<NeoML::CDnnBlob>& blob) const
{
	RETURN_IF(!m_dataset);
	GetSamples(iter, batchSize, blob, true);
}

//.............................................................................

void DatasetMNIST_NeoML::GetTrainLabels(int iter, int batchSize, FObj::CPtr<NeoML::CDnnBlob>& blob) const
{
	RETURN_IF(!m_dataset);
	GetLabels(iter, batchSize, blob, true);
}

//.............................................................................

void DatasetMNIST_NeoML::GetTestSamples(int iter, int batchSize, FObj::CPtr<NeoML::CDnnBlob>& blob) const
{
	RETURN_IF(!m_dataset);
	GetSamples(iter, batchSize, blob, false);
}

//.............................................................................

void DatasetMNIST_NeoML::GetTestLabels(int iter, int batchSize, FObj::CPtr<NeoML::CDnnBlob>& blob) const
{
	RETURN_IF(!m_dataset);
	GetLabels(iter, batchSize, blob, false);
}

//.............................................................................

void DatasetMNIST_NeoML::GetSamples(int iter, int batchSize, CPtr<NeoML::CDnnBlob>& blob, bool isTrain) const
{
	auto* buf = blob->GetBuffer<float>(0, blob->GetDataSize());

	const int sampleSize = blob->GetDataSize() / batchSize;
	const int multIterBatchSize = iter * batchSize;

	for (int i = 0; i < batchSize; ++i)
	{
		const int bufIndex = i * sampleSize;
		const int index = i + multIterBatchSize;
		if (isTrain)
		{
			for (int j = 0; j < sampleSize; ++j)
				buf[bufIndex + j] = m_dataset->training_images[m_shuffleIndicies[index]][j] / 255.f;
		}
		else
		{
			for (int j = 0; j < sampleSize; ++j)
				buf[bufIndex + j] = m_dataset->test_images[index][j] / 255.f;
		}
	}
}

//.............................................................................

void DatasetMNIST_NeoML::GetLabels(int iter, int batchSize, CPtr<NeoML::CDnnBlob>& blob, bool isTrain) const
{
	blob->Clear();
	blob->Fill(0.0f);
	auto* buf = blob->GetBuffer<float>(0, blob->GetDataSize());

	const int labelSize = blob->GetDataSize() / batchSize;
	const int multIterBatchSize = iter * batchSize;

	for (int i = 0; i < batchSize; ++i)
	{
		if (isTrain)
			buf[i * labelSize + m_dataset->training_labels[m_shuffleIndicies[i + multIterBatchSize]]] = 1.0f;
		else
			buf[i * labelSize + m_dataset->test_labels[i + multIterBatchSize]] = 1.0f;
	}
}

}