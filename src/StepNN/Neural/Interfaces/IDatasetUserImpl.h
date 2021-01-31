#pragma once

#include "IDatasetUser.h"

#include "StepNNLib.h"

namespace StepNN::Neural::Interfaces {

template<typename T>
class STEPNN_API IDatasetUserImpl : virtual public IDatasetUser
{
public:
	using Ptr = T*;
	virtual ~IDatasetUserImpl() = default;

	Ptr GetDatasetImpl()
	{
		Ptr impl = nullptr;
		auto datasetSP = GetDataset();
		if (datasetSP)
			impl = dynamic_cast<Ptr>(datasetSP.get());

		assert(impl);
		return impl;
	}
};

}