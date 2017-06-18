#pragma once

template <class entity_type>
class StateMachine
{
private:
	entity_type* m_pOwner;
	State<entity_type>* m_pCurrentState;
	State<entity_type>* m_pPreviousState;
	State<entity_type>* m_pGlobalState;

public:
	StateMachine(entity_type* owner);

	void SetCurrentState(State<entity_type>* pState) { m_pCurrentState = pState; }
	void SetGlobalState(State<entity_type>* pState) { m_pGlobalState = pState; }
	void SetPreviousState(State<entity_type>* pState) { m_pPreviousState = pState; }

	State<entity_type>* GetCurrentState() const { return m_pCurrentState; }
	State<entity_type>* GetGlobalState() const { return m_pGlobalState; }
	State<entity_type>* GetPreviousState() const { return m_pPreviousState; }

	void Update() const;

	void ChangeState(State<entity_type>* pNewState);
	void RevertToPreviousState();

	bool IsInState(const State<entity_type>& st > const;
};