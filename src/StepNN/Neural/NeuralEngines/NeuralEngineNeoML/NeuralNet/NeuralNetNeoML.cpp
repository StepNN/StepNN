#include "NeuralNetNeoML.h"

using namespace StepNN::Interfaces;

namespace StepNN {

class NeuralNetNeoML::Impl
{
};

}

namespace StepNN {



NeuralNetNeoML::NeuralNetNeoML()
	: m_impl(std::make_unique<Impl>())
{}

}