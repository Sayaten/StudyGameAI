#include "CookStew.h"
#include "../Global/GlobalFunctions.h"
#include "../Message/MessageDispatcher.h"

#include <iostream>
#include <WinBase.h>

using namespace std;

CookStew* CookStew::GetInstance()
{
	if (instance == NULL)
		instance = new CookStew;

	return instance;
}

void CookStew::Enter(Wife* pWife)
{
	if(!pWife->IsCooking())
	{
		cout << "\n" << GetNameOfEntity(pWife->GetID())
			<< ": Puttin' the stew in the oven";

		Dispatch->DispatchMessage(1.5,
			pWife->GetID(),
			pWife->GetID(),
			Msg_StewReady,
			NO_ADDITIONAL_INFO);

		pWife->SetCooking(true);
	}
}

void CookStew::Execute(Wife* pWife)
{

}

void CookStew::Exit(Wife* pWife)
{

}

bool CookStew::OnMessage(Wife* pWife, const Telegram& msg)
{
	switch(msg.m_msg)
	{
	case Msg_StewReady:
		cout << "\nMessage received by " << GetNameOfEntity(pWife->GetID())
			<< " at time: " << GetCurrentTime();

		cout << "\n" << GetNameOfEntity(pWife->GetID())
			<< ": Stew ready! Let's eat";

		Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY,
			pWife->GetID(),
			ent_Miner_Bob,
			Msg_StewReady,
			NO_ADDITIONAL_INFO);

		pWife->SetCooking(true);

		return true;
	}

	return false;
}