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
	return m_damagePoints;
}

void Person::subHealthPoints(long damage)
{
	m_healthPoints = m_healthPoints - damage;
	std::cout << m_name << " has lost " << damage << " health!\n";
}

void Person::die()
{
	m_alive = false;
	std::cout << m_name << " has been slain!";
}
