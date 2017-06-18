#include "Wife.h"


Wife::Wife(int id)
: BaseGameEntity(id)
, bCooking(false)
{

}

void Wife::Update()
{

}

void Wife::ChangeState(State<Wife>* pNewState)
{

}

void Wife::RevertToPreviousState()
{

}

bool Wife::HandleMessage(const Telegram& msg)
{
	return false;
}