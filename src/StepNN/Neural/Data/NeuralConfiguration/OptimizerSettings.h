#pragma once

#include "StepNN/Utils/Interfaces/AutoZero.h"

#include "StepNNLib.h"

namespace StepNN {

enum class STEPNN_API OptimizerType
{
	Undefined,
	Adam,
	Adagrad,
	LBFGS,
	SGD,
};

struct STEPNN_API OptimizerSettings
{
	OptimizerSettings() = default;
	OptimizerSettings(OptimizerType t) : type(t) {}
	virtual ~OptimizerSettings() = default;

	Z<OptimizerType, OptimizerType::Undefined> type;
	double lr { 1e-3 }; // learning rate
};

struct STEPNN_API AdamSettings : public OptimizerSettings
{
	AdamSettings()
		: OptimizerSettings(OptimizerType::Adam)
	{}

	double eps { 1e-8 };
	double beta1 { 0.9 };
	double beta2 { 0.999 };
	double weight_decay { 0.0 };
	bool amsgrad { false };
};

}