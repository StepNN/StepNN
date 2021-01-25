#pragma once

#include <memory>

#include "src/Neural/Interfaces/INeuralNet.h"

using namespace StepNN::Interfaces;

namespace StepNN {

class NeuralNetNeoML : public INeuralNet
{
public:
	NeuralNetNeoML();

private:
	class Impl;
	std::unique_ptr<Impl> m_impl;
};

}