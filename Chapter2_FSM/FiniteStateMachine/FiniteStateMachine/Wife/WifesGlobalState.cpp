#include "WifesGlobalState.h"
#include "../Global/GlobalFunctions.h"

#include <iostream>
#include <winbase.h>


using namespace std;

WifesGlobalState* WifesGlobalState::GetInstance()
{
	if (instance == NULL)
		instance = new WifesGlobalState;

	return instance;
}

void WifesGlobalState::Enter(Wife* pWife)
{

}

void WifesGlobalState::Execute(Wife* pWife)
{

}

void WifesGlobalState::Exit(Wife* pWife)
{

}

bool WifesGlobalState::OnMessage(Wife* pWife, const Telegram& msg)
{
	switch(msg.m_msg)
	{
	case Msg_HiHoneyImHome:
		{
		cout << "\nMessage handled by " << GetNameOfEntity(pWife->GetID())
			<< " at time: " << GetCurrentTime();

		cout << "\n" << GetNameOfEntity(pWife->GetID())
			<< ": Hi honey. Let me make you some of mah fine country stew";

		pWife->GetFSM()->ChangeState(CookStew::GetInstance());
		}
		return true;
	}
	return false;
}