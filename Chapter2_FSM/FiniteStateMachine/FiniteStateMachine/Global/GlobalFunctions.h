#pragma once
#include <string>

using namespace std;

// 임시로 배열로 처리
string strEntity[]
{
	"Bob",
	"Elsa"
};

enum receivers
{
	ent_Miner_Bob,
	ent_Elsa,
};

string GetNameOfEntity(int id)
{
	return strEntity[id];
}