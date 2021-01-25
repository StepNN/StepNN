#include "NeuralNetTF.h"

using namespace StepNN::Interfaces;

namespace StepNN {

class NeuralNetTF::Impl
{
};

}

namespace StepNN {

NeuralNetTF::NeuralNetTF()
	: m_impl(std::make_unique<Impl>())
{}

}