#pragma once

#include <set>
#include "Telegram.h"
#include "BaseGameEntity.h"

class MessageDispatcher
{
private:
	std::set<Telegram> PriorityQ;
	void Discharge(BaseGameEntity* pReceiver, const Telegram& msg);
	MessageDispatcher() {}

	static MessageDispatcher* instance;

public:
	static MessageDispatcher* GetInstance();
	void DispatchMessage(	double	delay,
										int			sender,
										int			receiver,
										int			msg,
										void*		ExtraInfo);

	void DispatchDelayedMessages();
};

#define Dispatch MessageDispatcher::GetInstance();