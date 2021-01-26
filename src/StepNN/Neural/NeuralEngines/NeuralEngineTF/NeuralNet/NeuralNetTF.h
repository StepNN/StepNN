#pragma once

#include <memory>

#include "StepNN/Neural/Interfaces/INeuralNet.h"

using namespace StepNN::Interfaces;

namespace StepNN {

class NeuralNetTF : public INeuralNet
{
public:
	NeuralNetTF();

private:
	class Impl;
	std::unique_ptr<Impl> m_impl;
};

}