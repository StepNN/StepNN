#pragma once

namespace StepNN {

template<typename IHandler>
class EventPublisher
{
protected:
	using Handler = IHandler;

public:
	virtual ~EventPublisher() = default;

	virtual void RegisterEventHandler(Handler*) = 0;
	virtual void UnregisterEventHandler(Handler*) = 0;
};

}