#pragma once

#include <memory>

#include "StepNN/Neural/Impl/NeoML/Dataset/DatasetNeoML.h"

#include "Decoder/mnist_reader.hpp"

namespace StepNN::Dataset {

class DatasetNeoML_MNIST : public Neural::DatasetNeoML
{
public:
	explicit DatasetNeoML_MNIST();
	~DatasetNeoML_MNIST();

// BaseDataset
	void Open(const std::string& filename) override;
	size_t GetTrainSize() const override;
	size_t GetTestSize() const override;
//

/// DatasetNeoML
	void GetTrainSamples(int iter, int batchSize, FObj::CPtr<NeoML::CDnnBlob>& blob) const override;
	void GetTrainLabels(int iter, int batchSize, FObj::CPtr<NeoML::CDnnBlob>& blob) const override;
	void GetTestSamples(int iter, int batchSize, FObj::CPtr<NeoML::CDnnBlob>& blob) const override;
	void GetTestLabels(int iter, int batchSize, FObj::CPtr<NeoML::CDnnBlob>& blob) const override;
///

private:
	void GetSamples(int iter, int batchSize, CPtr<NeoML::CDnnBlob>& blob, bool isTrain) const;
	void GetLabels(int iter, int batchSize, CPtr<NeoML::CDnnBlob>& blob, bool isTrain) const;

private:
	using DatasetImpl = mnist::MNIST_dataset<std::vector, std::vector<uint8_t>, uint8_t>;
	std::unique_ptr<DatasetImpl> m_dataset;
};
 
}