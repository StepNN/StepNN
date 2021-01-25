#include "NeuralNetTorch.h"

using namespace StepNN::Interfaces;

namespace StepNN {

class NeuralNetTorch::Impl
{
};

}

namespace StepNN {

NeuralNetTorch::NeuralNetTorch()
	: m_impl(std::make_unique<Impl>())
{}

}