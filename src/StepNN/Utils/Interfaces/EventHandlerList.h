#pragma once

#include <algorithm>
#include <functional>
#include <mutex>
#include <vector>

#include "EventPublisher.h"

namespace StepNN {

template <typename IHandler>
class EventHandlerList : virtual public EventPublisher<IHandler>
{
protected:
	using EventHandler = typename EventPublisher<IHandler>::Handler;

public:
	virtual void RegisterEventHandler(EventHandler* handler) override
	{
		if (!handler)
			return;

		std::unique_lock<std::recursive_mutex> lock(m_accessGuard);

		if (std::none_of(m_subscribers.begin(), m_subscribers.end(), [&handler](const auto& item) { return handler == item; }))
			m_subscribers.push_back(handler);
	}

	virtual void UnregisterEventHandler(EventHandler* handler) override
	{
		if (!handler)
			return;

		std::unique_lock<std::recursive_mutex> lock(m_accessGuard);

		if (auto it = std::find(m_subscribers.begin(), m_subscribers.end(), handler); it != m_subscribers.end())
			m_subscribers.erase(it);
	}

	template<typename FunctorType>
	void PerformForEachEventHandler(FunctorType functor)
	{
		std::vector<EventHandler*> subscribersCopy;

		{
			std::unique_lock<std::recursive_mutex> lock(m_accessGuard);
			subscribersCopy = m_subscribers;
		}

		{
			std::unique_lock<std::recursive_mutex> lock(m_notificationGuard);

			for (const auto& handler : subscribersCopy)
				std::bind(functor, handler);
		}
	}

	template<typename F, typename ...ARGS>
	void PerformAll(F function, ARGS&&... args)
	{
		PerformForEachEventHandler(std::bind(function, std::placeholders::_1, std::forward<ARGS>(args)...));
	}

private:
	std::vector<EventHandler*> m_subscribers;
	std::recursive_mutex m_accessGuard;
	std::recursive_mutex m_notificationGuard;
};

}