#pragma once

#include "StepNN/Neural/Interfaces/INeuralEngine.h"
#include "StepNN/Neural/Interfaces/INeuralNet.h"
#include "StepNN/Neural/Interfaces/IDatasetController.h"

#include "StepNN/Neural/Impl/NeoML/Interfaces/IControllerNeoML.h"
#include "StepNN/Neural/Impl/NeoML/Interfaces/IEventHandlerNeoML.h"

namespace NeoML {
	class IMathEngine;
	class IGpuMathEngineManager;
}

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

class NeuralEngineNeoML
	: public INeuralEngine
	, virtual public IDatasetController
	, virtual public IControllerNeoML
	, public IEventHandlerNeoML
{
public:
	explicit NeuralEngineNeoML();
	~NeuralEngineNeoML();

/// INeuralEngine
	ILayerEngine& GetLayerEngine() override;
	const ILayerEngine& GetLayerEngine() const override;
	INeuralConfigurator& GetConfigurator() override;
	const INeuralConfigurator& GetConfigurator() const override;
	IDatasetController& GetDatasetController() override { return *this; }
	const IDatasetController& GetDatasetController() const override { return *this; }
	bool SwitchImpl(NeuralFrameworkType type) override;
///

/// IEventHandlerNeoML
private:
	void OnSetNeuralConfiguration(const NeuralConfiguration&) override;
///

private:
	std::unique_ptr<ILayerEngine> m_layerEngine;
	std::unique_ptr<INeuralNet> m_net;
};

}