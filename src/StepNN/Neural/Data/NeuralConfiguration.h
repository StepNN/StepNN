#pragma once

#include "DeviceType.h"

#include "StepNNLib.h"

namespace StepNN {

struct STEPNN_API NeuralConfiguration
{
	int epochCount;
	int batchSize;

	int sampleWidth;
	int sampleHeight;
	int sampleChannels;

	DeviceType deviceType; 
	size_t memoryLimit;
};

}