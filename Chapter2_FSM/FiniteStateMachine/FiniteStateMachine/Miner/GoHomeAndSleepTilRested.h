#pragma once

#include "../StateMachine/State.h"
#include "Miner.h"

class GoHomeAndSleepTilRested : public State<Miner>
{
private:
	GoHomeAndSleepTilRested() {}
	static GoHomeAndSleepTilRested* instance;

public:
	static GoHomeAndSleepTilRested* GetInstance();

	virtual void Enter(Miner* pMiner);
	virtual void Execute(Miner* pMiner);
	virtual void Exit(Miner* pMiner);

	bool OnMessage(Miner* pMiner, const Telegram& msg);
};