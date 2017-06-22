// essential headers
#include <string>
#include "stdafx.h"
#include <iostream>
#include <sstream>

// awesome headers
#include "GeneralFunctions.h"
#include "Person.h"

Person::Person() :
	m_name{ "" }, m_healthPoints{ 100 }, m_maxHealthPoints{ 100 },
	m_alive{ true }, m_damagePoints{ 1 }, m_level {1}
{

}

int Person::returnLevel()
{
	return m_level;
}

bool Person::returnAlive()
{
	return m_alive;
}

long Person::returnDamagePoints()
{
	long currentDamage = getRandomNumber(m_damagePoints, m_maxDamagePoints);
	
	std::cout << m_name << " dealt " << currentDamage <<
		" damage!\n";
	return currentDamage;
}

void Person::subHealthPoints(long damage)
{
	if (m_healthPoints <= damage)
	{
		std::cout << m_name << " has lost " << damage << " health!\n";
		die();
	}
	else
	{
		m_healthPoints = m_healthPoints - damage;
		std::cout << m_name << " has lost " << damage << " health!\n";
	}
}

void Person::addHealthPoints(long giveHealth)
{
	std::cout << "You gained " << giveHealth << " health!\n";
	long aftermathHealth = m_healthPoints + giveHealth;

	if (aftermathHealth > m_maxHealthPoints)
	{
		m_healthPoints = m_maxHealthPoints;
	}
	else
	{
		m_healthPoints = aftermathHealth;
	}
}

void Person::die()
{
	m_alive = false;
	std::cout << m_name << " died!\n";
}
