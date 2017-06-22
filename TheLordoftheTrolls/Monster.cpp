#include "stdafx.h"
#include <iostream>
#include <string>


#include "Monster.h"
#include "GeneralFunctions.h"
#include "Person.h"
#include "Player.h"


Monster::Monster(int level)
{
	m_level = level;
	
	m_giveExperience = 100 * m_level;

	int ranNum = getRandomNumber(1, MONSTERTYPE_MAX - 1);

	switch (ranNum)
	{
		case MONSTERTYPE_ORC:
			m_name = "Orc";
			m_healthPoints = 50 * (m_level * m_level);
			m_damagePoints = 4 * (m_level * m_level);
			m_maxDamagePoints = 5 * (m_level * m_level);
			break;
		case MONSTERTYPE_TROLL:
			m_name = "Troll";
			m_healthPoints = 40 * (m_level * m_level);
			m_damagePoints = 5 * (m_level * m_level);
			m_maxDamagePoints = 6 * (m_level * m_level);
			break;
		case MONSTERTYPE_GOBLIN:
			m_name = "Goblin";
			m_healthPoints = 30 * (m_level * m_level);
			m_damagePoints = 6 * (m_level * m_level);
			m_maxDamagePoints = 7 * (m_level * m_level);
			break;
		case MONSTERTYPE_SPIDER:
			m_name = "Spider";
			m_healthPoints = 60 * (m_level * m_level);
			m_damagePoints = 3 * (m_level * m_level);
			m_maxDamagePoints = 4 * (m_level * m_level);
			break;
		case MONSTERTYPE_SLIME:
			m_name = "Slime";
			m_healthPoints = 70 * (m_level * m_level);
			m_damagePoints = 2 * (m_level * m_level);
			m_maxDamagePoints = 3 * (m_level * m_level);
			break;
	}

	std::cout << "You met a " << m_name << " with " << m_healthPoints <<
		" health and " << m_damagePoints << " to " << m_maxDamagePoints <<
		" damage!\n" <<	"Now you must stand and fight to the death!\n";
}

int Monster::returnGiveExperience()
{
	return m_giveExperience;
}


void Monster::printMonsterInfo()
{
	std::cout << "You are currently fighting a level " << m_level << " " << m_name << ", with " <<
		m_healthPoints << " health and " << m_damagePoints << " to " << 
		m_maxDamagePoints << " damage!\n";
}