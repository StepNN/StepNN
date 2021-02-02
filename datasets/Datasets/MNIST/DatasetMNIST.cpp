#include <cassert>

#include "Impl/DatasetMNIST_NeoML.h"

#include "DatasetMNIST.h"

namespace StepNN::Dataset {

std::shared_ptr<IDataset> CreateDatasetMNIST(NeuralFrameworkType type)
{
	switch(type)
	{
#ifdef STEPNN_USE_NEOML
	case NeuralFrameworkType::NeoML:
		return std::make_shared<DatasetMNIST_NeoML>();
		break;
#endif
	default:
		return nullptr;
	}
}

}