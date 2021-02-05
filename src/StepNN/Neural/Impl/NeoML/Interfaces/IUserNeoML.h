#pragma once

#include <memory>

#include "StepNN/Neural/Impl/NeoML/CommonNeoML.h"

namespace StepNN::Neural {

class IUserNeoML
{
public:
	virtual ~IUserNeoML() = default;

	virtual void SetMathEngine(const std::weak_ptr<NeoML::IMathEngine>& engine) { m_mathEngine = engine; }
	virtual void SetGpuManager(const std::weak_ptr<NeoML::IGpuMathEngineManager>& gpuManager) { m_gpuManager = gpuManager; }

protected:
	std::shared_ptr<NeoML::IMathEngine> GetMathEngine(bool required = true) const
	{
		const auto mathEngine = m_mathEngine.lock();
		if (!mathEngine && required)
			assert(!"IUserNeoML: mathEngine is nullptr!");

		return mathEngine;
	}

	std::shared_ptr<NeoML::IGpuMathEngineManager> GetGpuManager(bool required = true) const
	{
		const auto gpuManager = m_gpuManager.lock();
		if (!gpuManager && required)
			assert(!"IUserNeoML: gpuManager is nullptr!");

		return gpuManager;
	}

protected:
	std::weak_ptr<NeoML::IMathEngine> m_mathEngine;
	std::weak_ptr<NeoML::IGpuMathEngineManager> m_gpuManager;
};

}
