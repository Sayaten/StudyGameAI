#pragma once

#include "../Message/Telegram.h"

class BaseGameEntity
{
private:
	int m_ID;

	static int m_iNextValidID;

	void SetID(int val);

public:
	BaseGameEntity(int id) { 	SetID(id); }
	virtual ~BaseGameEntity() {}
	virtual void Update() = 0;
	int GetID() const { return m_ID; }
	virtual bool HandleMessage(const Telegram& msg) = 0;

	static int GetNextValidID() { return m_iNextValidID; }
	static void IncreaseNextValidID() { ++m_iNextValidID;  }
};