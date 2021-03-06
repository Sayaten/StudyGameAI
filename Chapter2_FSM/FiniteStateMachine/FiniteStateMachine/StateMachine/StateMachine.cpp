#include "StateMachine.h"

template <class entity_type>
void StateMachine::Update()
{
	if (m_pGlobalState)	m_pGlobalState->Execute(m_pOwner);
	if (m_pCurrentState) m_pCurrentState->Execute(m_pOwner);
}

template <class entity_type>
void StateMachine::ChangeState(State<entity_type>* pNewState)
{
	assert(pNewState &&
		"<StateMachine::ChangeState>: trying to change to a null state");

	m_pPreviousState = m_pCurrentState;

	m_pCurrentState->Exit(m_pOwner);

	m_pCurrentState = pNewState;

	m_pCurrentState->Enter(m_pOwner);
}

void StateMachine::RevertToPreviousState()
{
	ChangeState(m_pCurrentState);
}

template <class entity_type>
bool StateMachine::IsInState(const State<entity_type>& st )
{
	
}

bool StateMachine::HandleMessage(const Telegram& msg)
{
	if(m_pCurrentState && m_pCurrentState->OnMessage(m_pOwner, msg))
	{
		return true;
	}

	if(m_pGlobalState && m_pGlobalState->OnMessage(m_pOwner, msg))
	{
		return true;
	}

	return false;
}