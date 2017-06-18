#pragma once

#include <map>
#include "BaseGameEntity.h"

class EntityManager
{
private:
	typedef std::map<int, BaseGameEntity*> EntityMap;

private:
	EntityMap m_EntityMap;
	static EntityManager* instance;

	EntityManager(){}
	EntityManager(const EntityManager&);
	EntityManager& operator=(const EntityManager&);

public:
	static EntityManager* GetInstance();
	void RegisterEntity(BaseGameEntity* NewEntity);
	BaseGameEntity* GetEntityFromID(int id) const;
	void RemoveEntity(BaseGameEntity* pEntity);
};

#define EntityMgr EntityManager::GetInstance()