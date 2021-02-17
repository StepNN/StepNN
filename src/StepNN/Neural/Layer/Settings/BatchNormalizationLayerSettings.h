#pragma once

#include "StepNN/Types/CommonDefs.h"

#include "StepNN/Utils/Interfaces/AutoZero.h"

#include "BaseLayerSettings.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API BatchNormalizationLayerSettings : public BaseLayerSettings
{
public:
	LAYER_SETTINGS(BatchNormalizationLayerSettings)

	BatchNormalizationLayerSettings() = default;
	BatchNormalizationLayerSettings(const std::string& layerId) : BaseLayerSettings(layerId) {};

	bool operator==(const BatchNormalizationLayerSettings& rhs) const noexcept
	{
		return true
			&& BaseLayerSettings::operator==(rhs)
			&& m_numFeatures == rhs.m_numFeatures
			&& m_eps == rhs.m_eps
			&& m_momentum == rhs.m_momentum
			&& m_affine == rhs.m_affine
			&& m_trackRunningStats == rhs.m_trackRunningStats
			;
	}
	bool operator!=(const BatchNormalizationLayerSettings& rhs) const noexcept { return !(*this == rhs); }

	void SetNumFeatures(int64_t value) { m_numFeatures = value; }
	void SetEps(double value) { m_eps = value; }
	void SetMomentum(double value) { m_momentum = value; }
	void SetAffine(bool value) { m_affine = value; }
	void SetTrackRunningStats(bool value) { m_trackRunningStats = value; }

	int64_t GetNumFeatures() const noexcept { return m_numFeatures; }
	double GetEps() const noexcept { return m_eps; }
	double GetMomentum() const noexcept { return m_momentum; }
	bool GetAffine() const noexcept { return m_affine; }
	bool GetTrackRunningStats() const noexcept { return m_trackRunningStats; }

	bool IsEmpty() { return m_numFeatures.isDefault() || m_numFeatures == 0; }

protected:
	// Names and values was copied from libtorch
	Z<int64_t, Defs::INVALID_VALUE_INT> m_numFeatures;
	Z<double, 1, 100000> m_eps; // 1e-5
	Z<double, 1, 10> m_momentum; // 0.1
	Z<bool, true> m_affine;
	Z<bool, true> m_trackRunningStats;
};

}