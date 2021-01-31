#pragma once

#include "NeoML/Dnn/DnnBlob.h"

#include "StepNN/Neural/Interfaces/BaseDataset.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API DatasetNeoML : public BaseDataset
{
public:
	virtual void GetTrainSamples(int iter, int batchSize, FObj::CPtr<NeoML::CDnnBlob>& blob) const = 0;
	virtual void GetTrainLabels(int iter, int batchSize, FObj::CPtr<NeoML::CDnnBlob>& blob) const = 0;
	virtual void GetTestSamples(int iter, int batchSize, FObj::CPtr<NeoML::CDnnBlob>& blob) const = 0;
	virtual void GetTestLabels(int iter, int batchSize, FObj::CPtr<NeoML::CDnnBlob>& blob) const = 0;

protected:
	explicit DatasetNeoML() = default;
	virtual ~DatasetNeoML() = default;
};

}