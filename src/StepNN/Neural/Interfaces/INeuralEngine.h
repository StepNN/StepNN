#pragma once

#include "IDatasetController.h"
#include "ILayerEngine.h"
#include "INeuralConfigurator.h"

#include "StepNN/Neural/Data/NeuralFrameworkType.h"

#include "StepNNLib.h"

namespace StepNN::Neural::Interfaces {

class STEPNN_API INeuralEngine
{
public:
	virtual ~INeuralEngine() = default;

	virtual ILayerEngine& GetLayerEngine() = 0;
	virtual const ILayerEngine& GetLayerEngine() const = 0;

	virtual INeuralConfigurator& GetConfigurator() = 0;
	virtual const INeuralConfigurator& GetConfigurator() const = 0;

	virtual IDatasetController& GetDatasetController() = 0;
	virtual const IDatasetController& GetDatasetController() const = 0;

	virtual bool SwitchImpl(NeuralFrameworkType type) = 0;
};

}