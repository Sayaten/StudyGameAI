#pragma once

#include "../StateMachine/State.h"
#include "Wife.h"

class CookStew : State<Wife>
{
private:
	CookStew() {}
	static CookStew* instance;

public:
	static CookStew* GetInstance();

	virtual void Enter(Wife* pWife);
	virtual void Execute(Wife* pWife);
	virtual void Exit(Wife* pWife);

	bool OnMessage(Wife* pWife, const Telegram& msg);
};