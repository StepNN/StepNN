#pragma once

#include <memory>

#include "StepNN/Utils/Interfaces/EventHandlerList.h"

#include "StepNN/Neural/Interfaces/IDatasetUserImpl.h"
#include "StepNN/Neural/Interfaces/BaseNeuralNet.h"

#include "StepNN/Neural/Impl/NeoML/Dataset/DatasetNeoML.h"
#include "StepNN/Neural/Impl/NeoML/Interfaces/IUserNeoML.h"
#include "StepNN/Neural/Impl/NeoML/Interfaces/IEventHandlerNeoML.h"
#include "StepNN/Neural/Impl/NeoML/Layers/BaseLayerNeoML.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

class NeuralNetNeoML
	: virtual public BaseNeuralNet
	, virtual public IDatasetUserImpl<DatasetNeoML>
	, public IUserNeoML
	, public EventHandlerList<IEventHandlerNeoML>
{
public:
	explicit NeuralNetNeoML(const ILayerEngine* layerEngine);
	~NeuralNetNeoML();

/// INeuralConfigurator
	void SetNeuralConfiguration(const NeuralConfiguration&);
	void SetNeuralConfiguration(NeuralConfiguration&&);
	void SetDeviceType(DeviceType type);
///

/// ITrainable
	void Train() override;
///

private:
	void OnSetNeuralConfiguration();
	void Configure(NeoML::CDnn& dnn);

	BaseLayerNeoML* CastLayer(ILayer*);
};

}
