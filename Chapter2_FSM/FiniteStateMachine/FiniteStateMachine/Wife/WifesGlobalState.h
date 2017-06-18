#pragma once

#include "../StateMachine/State.h"
#include "../Message/Telegram.h"
#include "Wife.h"

class WifesGlobalState : public State<Wife>
{
private:
	WifesGlobalState() {}
	static WifesGlobalState* instance;

public:
	static WifesGlobalState* GetInstance();

	virtual void Enter(Wife* pWife);
	virtual void Execute(Wife* pWife);
	virtual void Exit(Wife* pWife);

	bool OnMessage(Wife* pWife, const Telegram& msg);
};