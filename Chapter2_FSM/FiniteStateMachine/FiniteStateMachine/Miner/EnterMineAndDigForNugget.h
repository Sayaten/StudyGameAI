#pragma once

#include "../StateMachine/State.h"
#include "Miner.h"

class EnterMineAndDigForNugget : public State<Miner>
{
private:
	EnterMineAndDigForNugget(){}
	static EnterMineAndDigForNugget* instance;

public:
	static EnterMineAndDigForNugget* GetInstance();

	virtual void Enter(Miner* pMiner);
	virtual void Execute(Miner* pMiner);
	virtual void Exit(Miner* pMiner);
	
	bool OnMessage(Miner* pMiner, const Telegram& msg);
};