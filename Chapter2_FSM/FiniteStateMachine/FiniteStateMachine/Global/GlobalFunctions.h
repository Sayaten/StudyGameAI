#pragma once
#include <string>

using namespace std;

// �ӽ÷� �迭�� ó��
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