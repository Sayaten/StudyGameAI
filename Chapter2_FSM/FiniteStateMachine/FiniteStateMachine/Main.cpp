#include "Miner.h"
#include "EntityManager.h"

int main()
{
	Miner* Bob = new Miner(0); // enumerated ID
	EntityMgr->RegisterEntity(Bob);

	return 0;
}