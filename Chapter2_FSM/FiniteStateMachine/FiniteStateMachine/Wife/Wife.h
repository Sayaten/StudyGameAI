#pragma once

#include "../Global/BaseGameEntity.h"
#include "../StateMachine/State.h"
#include "../StateMachine/StateMachine.h"

class Wife : public BaseGameEntity
{
	StateMachine<Wife>* m_pStateMachine;
	State<Wife>*	 m_pCurrentState;
	State<Wife>*	 m_pPreviousState;
	State<Wife>*	 m_pGlobalState;
	location_type m_eLocation;
	bool m_bCooking;

public:
	Wife(int id);
	~Wife() { delete m_pStateMachine; }
	virtual void Update();
	void ChangeState(State<Wife>* pNewState);
	void RevertToPreviousState();

	location_type GetLocation() { return m_eLocation; }
	void SetLocation(location_type location) { m_eLocation = location; }
	StateMachine<Wife>* GetFSM() const { return m_pStateMachine; }

	bool IsCooking() { return m_bCooking; }
	void SetCooking(bool bCooking) { m_bCooking = bCooking; }

	bool HandleMessage(const Telegram& msg);

};