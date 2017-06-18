#include "Miner.h"
#include <cassert>


Miner::Miner(int id)
: m_eLocation(shack)
, m_iGoldCarried(0)
, m_iMoneyInBank(0)
, m_iThirst(0)
, m_iFatigue(0)
, BaseGameEntity(id)
{

}

void Miner::Update()
{
	++m_iThirst;
	m_pStateMachine->Update();

	if (m_pCurrentState)
	{
		m_pCurrentState->Execute(this);
	}
}

void Miner::ChangeState(State<Miner>* pNewState)
{
	assert(m_pCurrentState && pNewState);

	m_pCurrentState->Exit(this);

	m_pCurrentState = pNewState;

	m_pCurrentState->Enter(this);
}

void Miner::RevertToPreviousState()
{
	m_pPreviousState = m_pCurrentState;
	m_pCurrentState = m_pGlobalState;
}

bool Miner::HandleMessage(const Telegram& msg)
{
	return m_pStateMachine->HandleMessage(msg);
}
