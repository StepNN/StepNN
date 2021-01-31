#include <algorithm>
#include <cassert>
#include <numeric>
#include <random>

#include "StepNN/Types/CommonDefs.h"

#include "BaseDataset.h"

namespace StepNN::Neural {

void BaseDataset::Open(const std::string& filename)
{
	assert(false);
}

//.............................................................................

size_t BaseDataset::GetTrainSize() const
{
	assert(false);
	return Defs::INVALID_VALUE_SIZE_T;
}

//.............................................................................

size_t BaseDataset::GetTestSize() const
{
	assert(false);
	return Defs::INVALID_VALUE_SIZE_T;
}

//.............................................................................

void BaseDataset::Reshuffle()
{
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(m_shuffleIndicies.begin(), m_shuffleIndicies.end(), g);
}

//.............................................................................

}