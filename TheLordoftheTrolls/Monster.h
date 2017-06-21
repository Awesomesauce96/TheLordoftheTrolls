#pragma once

#include "Person.h"

class Monster : public Person
{
	long m_giveExperience;

public:
	Monster() = delete;
	Monster(int level);

	int Monster::returnGiveExperience();
	void Monster::printMonsterInfo();
};


enum eMonsterType {
	MONSTERTYPE_ORC = 1,
	MONSTERTYPE_TROLL = 2,
	MONSTERTYPE_GOBLIN = 3,
	MONSTERTYPE_SPIDER = 4,
	MONSTERTYPE_SLIME = 5,
	MONSTERTYPE_MAX
};