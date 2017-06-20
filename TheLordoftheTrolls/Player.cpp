#include "stdafx.h"
#include <iostream>
#include <string>


// awesome headers
#include "Person.h"
#include "Player.h"
#include "GeneralFunctions.h"


Player::Player() : 
	m_experience{ 100 }, m_maxExperience{ 100 }
{
	Person::m_name = getPlayerName();
	m_class = getPlayerClass();

	switch (m_class)
	{
		case PLAYERCLASS_WARRIOR:
			m_className = "Warrior";
			m_classWeapon = "Great-Sword";
			Person::m_healthPoints = 200;
			Person::m_damagePoints = 10;
			break;
		case PLAYERCLASS_ROGUE:
			m_className = "Rogue";
			m_classWeapon = "Daggers";
			Person::m_healthPoints = 170;
			Person::m_damagePoints = 13;
			break;
		case PLAYERCLASS_MAGE:
			m_className = "Mage";
			m_classWeapon = "Fireball";
			Person::m_healthPoints = 150;
			Person::m_damagePoints = 15;
			break;
	}

	Person::m_level = 1;
	Person::m_maxHealthPoints = Person::m_healthPoints;

}

std::string Player::getPlayerName()
{
	while (true)
	{
		std::cout << "Please enter a name for your character...\n";
		std::string playerName;
		std::getline(std::cin, playerName);

		bool strRejected = false;
		for (unsigned int index = 0; index < playerName.length() && !strRejected; ++index)
		{
			if (isalpha(playerName[index]))
			{
				continue;
			}
			if (playerName[index] == ' ')
			{
				continue;
			}
			strRejected = true;
		}

		if (!strRejected)
			return playerName;
	}
}


int Player::getPlayerClass()
{
	while (true)
	{
		std::cout << "Please enter what class you want to play by picking a number!\n";
		std::cout << PLAYERCLASS_WARRIOR << ": The Warrior!\n";
		std::cout << PLAYERCLASS_ROGUE << ": The Rogue!\n";
		std::cout << PLAYERCLASS_MAGE << ": The Mage!\n";

		int playerClass;
		std::cin >> playerClass;

		if (std::cin.fail())
		{
			cinFailHandling();
			continue;
		}
		if (playerClass >= PLAYERCLASS_MAX)
		{
			std::cout << "That number does not represent a class!\n";
			continue;
		}

		return playerClass;

	}
}

void Player::printPlayerInfo()
{
	std::cout << "Your character's name is: " << Person::m_name << ".\n";
	std::cout << "Class: " << m_className << ".\n";
	std::cout << "Level: " << Person::m_level << ".\n";
	std::cout << "Health: " << Person::m_healthPoints << ".\n";
	std::cout << "Damage with " << m_classWeapon << ": " << Person::m_damagePoints << ".\n";
	std::cout << "You need: " << m_experience << " experience to level up!\n";
}

void Player::levelUp()
{
	Person::m_level = Person::m_level + 1;
	Person::m_maxHealthPoints = Person::m_maxHealthPoints * Person::m_level;
	Person::m_damagePoints = Person::m_damagePoints * Person::m_level;
	Person::m_healthPoints = Person::m_maxHealthPoints;
	m_maxExperience = m_maxExperience * m_level;
	m_experience = m_maxExperience;
	std::cout << "Congratulations, you leveled up!\n";
}

void Player::addExperience(long experience)
{
	std::cout << "You gained " << experience << " experience!\n";
	if (m_experience < experience)
	{
		long overloadedExperience = experience - m_experience;
		levelUp();
		addExperience(overloadedExperience);
	}
	else if (m_experience == experience)
	{
		levelUp();
	}
	else
	{
		m_experience = m_experience - experience;
	}
}