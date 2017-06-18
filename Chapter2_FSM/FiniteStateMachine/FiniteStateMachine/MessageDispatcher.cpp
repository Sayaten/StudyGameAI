#include "MessageDispatcher.h"
#include "EntityManager.h"
#include "Telegram.h"
#include <winbase.h>

MessageDispatcher* MessageDispatcher::GetInstance()
{
	if (instance == NULL)
		instance = new MessageDispatcher;

	return instance;
}

void MessageDispatcher::DispatchMessage(double delay, int sender, int receiver, int msg, void* ExtraInfo)
{
	BaseGameEntity* pReceiver = EntityMgr->GetEntityFromID(receiver);
	Telegram telegram(delay, sender, receiver, msg, ExtraInfo);

	if(delay < 0.0)
	{
		Discharge(pReceiver, telegram);
	}
	else
	{
		double currentTime = GetCurrentTime();

		telegram.m_dispatchTime = currentTime + delay;

		PriorityQ.insert(telegram);
	}
}

void MessageDispatcher::DispatchDelayedMessages()
{
	double currentTime = GetCurrentTime();

	while(	(PriorityQ.begin()->m_dispatchTime < currentTime) &&
				(PriorityQ.begin()->m_dispatchTime > 0) )
	{
		Telegram telegram = *PriorityQ.begin();
		BaseGameEntity* pReceiver = EntityMgr->GetEntityFromID(telegram.m_receiver);
		Discharge(pReceiver, telegram);
		PriorityQ.erase(PriorityQ.begin());
	}
}