#include "EnterMineAndDigForNugget.h"

#include <iostream>
#include "../Global/GlobalFunctions.h"

using namespace std;

EnterMineAndDigForNugget* EnterMineAndDigForNugget::GetInstance()
{
	if (instance == NULL)
		instance = new EnterMineAndDigForNugget;

	return instance;
}

void EnterMineAndDigForNugget::Enter(Miner* pMiner)
{
	if(pMiner->GetLocation() != goldmine)
	{
		cout  << "\n" << GetNameOfEntity(pMiner->GetID()) << ": "
				<< "Walkin' to the gold mine";
		pMiner->SetLocation(goldmine);
	}
}

void EnterMineAndDigForNugget::Execute(Miner* pMiner)
{
	pMiner->AddToGoldCarried(1);
	pMiner->IncreaseFatigue();

	cout << "\n" << GetNameOfEntity(pMiner->GetID()) << ": "
		<< "Pickin' up a nugget";

	if(pMiner->IsPocketsFull())
	{
		pMiner->ChangeState(VisitBankAndDepositGold::GetInstance());
	}

	if (pMiner->IsThirsty())
	{
		pMiner->ChangeState(QuenchThirst::GetInstance());
	}
}

void EnterMineAndDigForNugget::Exit(Miner* pMiner)
{
	cout << "\n" << , GetNameOfEntity(pMiner->GetID()) << ": "
			<< "Ah'm leavin' the gold mine mahpockets full o' sweet gold";
}

bool EnterMineAndDigForNugget::OnMessage(Miner* pMiner, const Telegram& msg)
{
	return false;
}