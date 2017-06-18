#include "GoHomeAndSleepTilRested.h"
#include "../Global/GlobalFunctions.h"
#include "../Message/MessageDispatcher.h"
#include "../Message/Telegram.h"

#include <iostream>
#include <winbase.h>

GoHomeAndSleepTilRested* GoHomeAndSleepTilRested::GetInstance()
{
	if (instance == NULL)
		instance = new GoHomeAndSleepTilRested;

	return instance;
}

void GoHomeAndSleepTilRested::Enter(Miner* pMiner)
{
	if(pMiner->GetLocation() != shack)
	{
		cout << "\n" << GetNameOfEntity(pMiner->GetID()) << ": "
				<< "Walkin' home";

		pMiner->SetLocation(shack);

		Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY,
			pMiner->GetID(),
			ent_Elsa,
			Msg_HiHoneyImHome,
			NO_ADDITIONAL_INFO);
	}
}

void GoHomeAndSleepTilRested::Execute(Miner* pMiner)
{

}

void GoHomeAndSleepTilRested::Exit(Miner* pMiner)
{

}

bool GoHomeAndSleepTilRested::OnMessage(Miner* pMiner, const Telegram& msg)
{
	switch (msg.m_msg)
	{
	case Msg_StewReady:
		cout << "\nMessage handled by " << GetNameOfEntity()
			<< " at time: " << GetCurrentTime();

		cout << "\n" << GetNameOfEntity(pMiner->GetID())
			<< ": Okay hun, ahm a-comin'!";

		pMiner->GetFSM()->ChangeState(EatStew::Instance());

		return true;
	}
}