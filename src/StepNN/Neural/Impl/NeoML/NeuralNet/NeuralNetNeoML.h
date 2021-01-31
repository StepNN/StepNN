#pragma once

#include <memory>

#include "StepNN/Neural/Interfaces/IDatasetUserImpl.h"
#include "StepNN/Neural/Interfaces/BaseNeuralNet.h"
#include "StepNN/Neural/Impl/NeoML/Dataset/DatasetNeoML.h"
#include "StepNN/Neural/Impl/NeoML/Layers/BaseLayerNeoML.h"

namespace NeoML {
	class IMathEngine;
	class IGpuMathEngineManager;
}

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

class NeuralNetNeoML
	: virtual public BaseNeuralNet
	, virtual public IDatasetUserImpl<DatasetNeoML>
{
public:
	explicit NeuralNetNeoML(const ILayerEngine* layerEngine);
	~NeuralNetNeoML();

/// INeuralConfigurator
	void SetNeuralConfiguration(const NeuralConfiguration&);
	void SetNeuralConfiguration(NeuralConfiguration&&);
	void SetDeviceType(DeviceType type);
///

/// INeuralNet
	void Configure() override;
	void ProcessTrain() override;
///

private:
	void OnSetNeuralConfiguration();
	void Configure(NeoML::CDnn& dnn);

	BaseLayerNeoML* CastLayer(ILayer*);

private:
	std::unique_ptr<NeoML::IGpuMathEngineManager> m_gpuManager;
	std::unique_ptr<NeoML::IMathEngine> m_mathEngine;
};

}
