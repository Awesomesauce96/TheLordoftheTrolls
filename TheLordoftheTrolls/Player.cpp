#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

// awesome headers
#include "Person.h"
#include "Player.h"
#include "GeneralFunctions.h"
#include "Spells.h"

Player::Player() :
	m_experience{ 100 }, m_maxExperience{ 100 }, m_potion(1, 5)
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
			Person::m_maxDamagePoints = 12;
			break;
		case PLAYERCLASS_ROGUE:
			m_className = "Rogue";
			m_classWeapon = "Daggers";
			Person::m_healthPoints = 170;
			Person::m_damagePoints = 13;
			Person::m_maxDamagePoints = 15;
			break;
		case PLAYERCLASS_MAGE:
			m_className = "Mage";
			m_classWeapon = "Fireball";
			Person::m_healthPoints = 150;
			Person::m_damagePoints = 15;
			Person::m_maxDamagePoints = 17;
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
	std::cout << "Damage with " << m_classWeapon << ": " << Person::m_damagePoints << " to " <<
		m_maxDamagePoints << ".\n";
	std::cout << "You need: " << m_experience << " experience to level up!\n";
	std::cout << "Health Potions: " << m_potion.returnQuantity() << ".\n";
}

void Player::levelUp()
{
	Person::m_level = Person::m_level + 1;
	Person::m_maxHealthPoints = Person::m_maxHealthPoints * Person::m_level;
	Person::m_damagePoints = Person::m_damagePoints * Person::m_level;
	m_maxDamagePoints = m_maxDamagePoints * m_level;
	Person::m_healthPoints = Person::m_maxHealthPoints;
	m_maxExperience = m_maxExperience * m_level;
	m_experience = m_maxExperience;
	m_potion.upgradePotion(returnLevel());
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

void Player::drinkPotion()
{
	m_potion.removeOnePotion();

	long aftermathHealth = m_healthPoints + m_potion.returnGiveHealth();

	if (aftermathHealth > m_maxHealthPoints)
	{
		m_healthPoints = m_maxHealthPoints;
	}
	else
	{
		m_healthPoints = aftermathHealth;
	}

	std::cout << "You now have " << m_potion.returnQuantity() << " health potions.\n";
}

void Player::rewardPotion()
{
	if (getRandomPercent(1))
	{
		m_potion.addPotionQuantity(3);
	}
	else if (getRandomPercent(10))
	{
		m_potion.addPotionQuantity(2);
	}
	else if (getRandomPercent(50))
	{
		m_potion.addPotionQuantity(1);
	}
	else
	{
		std::cout << "You were not rewarded any potions.\n";
	}

	std::cout << "You now have " << m_potion.returnQuantity() << " health potions.\n";
}

// overwrite function Person::returnDamagePoints
long Player::returnDamagePoints()
{
	long currentDamage = getRandomNumber(m_damagePoints, m_maxDamagePoints);
	
	std::cout << "You dealt " << currentDamage <<
		" damage with your " << m_classWeapon << "!\n";
	
	return currentDamage;
}

void Player::addSpell(Spell *spellName)
{
	m_spells.push_back(spellName);
}


int Player::returnClass()
{
	return m_class;
}

void Player::printSpells()
{
	if (m_spells[0] == 0)
		return;

	for (unsigned int iii = 0; iii < m_spells.size(); ++iii)
	{
		std::cout << iii << " - ";
		m_spells.at(iii)->printSpell(m_level);
	}
}


long Player::returnDamagePointsSpell()
{
	while (true)
	{
		std::cout << "Enter the id of the spells you want to use! -1 - shows current spells. -2 - cancel.\n";

		int getSpell;
		std::cin >> getSpell;

		if (std::cin.fail())
		{
			cinFailHandling();
		}
		std::cin.ignore(32767, '\n');

		if (getSpell == -1)
		{
			printSpells();
			continue;
		}
		if (getSpell == -2)
		{
			std::cout << "You canceled spellcasting and did no damage!\n";
			return 0;
		}
		if (getSpell >= 0 && getSpell < returnSpellsLength())
		{
			long spellDmg = m_spells.at(getSpell)->returnDamage(m_level);
			return spellDmg;
		}
		else
		{
			continue;
		}
	}
}

int Player::returnSpellsLength()
{
	int length = m_spells.size();
	return length;
}