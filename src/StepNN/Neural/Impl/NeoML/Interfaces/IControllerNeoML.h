#pragma once

#include "StepNN/Utils/Interfaces/IUserController.h"

#include "IUserNeoML.h"

namespace StepNN::Neural {

class IControllerNeoML : virtual public IUserController<IUserNeoML>
{
public:
	virtual ~IControllerNeoML() = default;

	void SetMathEngine(const std::shared_ptr<NeoML::IMathEngine>& engine)
	{
		m_mathEngine = engine;
		for (auto& user : m_users)
			user->SetMathEngine(engine);
	}

	void SetGpuManager(const std::shared_ptr<NeoML::IGpuMathEngineManager>& gpuManager)
	{
		m_gpuManager = gpuManager;
		for (auto& user : m_users)
			user->SetGpuManager(gpuManager);
	}

protected:
	std::shared_ptr<NeoML::IMathEngine> m_mathEngine;
	std::shared_ptr<NeoML::IGpuMathEngineManager> m_gpuManager;
};

}