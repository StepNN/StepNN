#pragma once

#include "IDatasetUser.h"

#include "StepNNLib.h"

namespace StepNN::Neural::Interfaces {

template<typename T>
class STEPNN_API IDatasetUserImpl : virtual public IDatasetUser
{
public:
	virtual ~IDatasetUserImpl() = default;

	T* GetDatasetImpl()
	{
		T* impl = nullptr;
		auto datasetSP = GetDataset();
		if (datasetSP)
			T* impl = dynamic_cast<T*>(m_dataset.get());

		assert(impl);
		return impl;
	}
};

}