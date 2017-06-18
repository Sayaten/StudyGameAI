#pragma once

#include "../Global/BaseGameEntity.h"
#include "../Message/Telegram.h"
#include "../StateMachine/State.h"
#include "../StateMachine/StateMachine.h"

#define MAX_GOLD_COUNT 10
#define MAX_THIRSTY_AMOUNT 10

class Miner : public BaseGameEntity
{
private:
	StateMachine<Miner>* m_pStateMachine;
	State<Miner>*	 m_pCurrentState;
	State<Miner>*	 m_pPreviousState;
	State<Miner>*	 m_pGlobalState;
	location_type m_eLocation;
	int m_iGoldCarried;
	int m_iMoneyInBank;
	int m_iThirst;
	int m_iFatigue;

public:
	Miner(int id);
	~Miner() { delete m_pStateMachine;  }
	virtual void Update();
	void ChangeState(State<Miner>* pNewState);
	void RevertToPreviousState();

	location_type GetLocation() { return m_eLocation;  }
	void SetLocation(location_type location) { m_eLocation = location; }
	StateMachine<Miner>* GetFSM() const { return m_pStateMachine; }

	void AddToGoldCarried(int count) { m_iGoldCarried += count; }
	void IncreaseFatigue() { ++m_iFatigue;  }

	bool IsPocketsFull() { return m_iGoldCarried == MAX_GOLD_COUNT;  }
	bool IsThirsty() { return m_iThirst == MAX_THIRSTY_AMOUNT;  }

	bool HandleMessage(const Telegram& msg);
};