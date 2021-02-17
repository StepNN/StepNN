#pragma once

#include <vector>

namespace StepNN {

template<typename IUserT>
class IUserController
{
public:
	using Ptr = IUserT*;

	virtual ~IUserController() = default;

	virtual void AddUser(Ptr user)
	{
		assert(user);
		m_users.push_back(user);
	}

protected:
	std::vector<Ptr> m_users;
};

}