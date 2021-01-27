#pragma once

#include <memory>

#include "StepNN/Neural/Interfaces/BaseNeuralNet.h"

namespace NeoML {
	class IMathEngine;
	class IGpuMathEngineManager;
}

using namespace StepNN::Interfaces;

namespace StepNN {

class NeuralNetNeoML : virtual public BaseNeuralNet
{
public:
	explicit NeuralNetNeoML(const ILayerEngine* layerEngine);
	~NeuralNetNeoML();

/// INeuralNet
///

/// INeuralConfigurator
	void SetNeuralConfiguration(const NeuralConfiguration&);
	void SetNeuralConfiguration(NeuralConfiguration&&);
	void SetDeviceType(DeviceType type);
///

private:
	void OnSetNeuralConfiguration();

private:
	std::unique_ptr<NeoML::IGpuMathEngineManager> m_gpuManager;
	std::unique_ptr<NeoML::IMathEngine> m_mathEngine;
};

}
