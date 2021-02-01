#pragma once

#include <memory>

#include "StepNN/Neural/Data/NeuralFrameworkType.h"
#include "StepNN/Neural/Interfaces/IDataset.h"

#include "StepNN_DatasetsLib.h"

using namespace StepNN::Neural;
using namespace StepNN::Neural::Interfaces;

namespace StepNN::Dataset {

STEPNN_DATASETS_API std::shared_ptr<IDataset> CreateDatasetMNIST(NeuralFrameworkType);

}