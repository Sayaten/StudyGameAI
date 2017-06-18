#include "EntityManager.h"

#include <iostream>

EntityManager* EntityManager::GetInstance()
{
	if (instance == NULL)
		instance = new EntityManager;

	return instance;
}

EntityManager& EntityManager::operator=(const EntityManager& rhs)
{
	return *this;
}

void EntityManager::RegisterEntity(BaseGameEntity* NewEntity)
{
	m_EntityMap.insert(std::make_pair(BaseGameEntity::GetNextValidID(), NewEntity));
	BaseGameEntity::IncreaseNextValidID();
}

BaseGameEntity* EntityManager::GetEntityFromID(int id) const
{
	return m_EntityMap.at(id);
}

void EntityManager::RemoveEntity(BaseGameEntity* pEntity)
{
	m_EntityMap.erase(pEntity->GetID());
}