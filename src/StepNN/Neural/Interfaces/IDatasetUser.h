#pragma once

#include <cassert>
#include <memory>

#include "IDataset.h"

#include "StepNNLib.h"

namespace StepNN::Neural::Interfaces {

class STEPNN_API IDatasetUser
{
public:
	virtual ~IDatasetUser() = default;

	virtual void SetDataset(const std::weak_ptr<IDataset>& dataset)
	{
		m_dataset = dataset;
	}

protected:
	std::shared_ptr<IDataset> GetDataset(bool required = true) const
	{
		const auto dataset = m_dataset.lock();
		if (!dataset && required)
			assert(!"IDatasetUser: dataset is nullptr!");

		return dataset;
	}

protected:
	std::weak_ptr<IDataset> m_dataset;
};

}