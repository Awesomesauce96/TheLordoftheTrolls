// essential headers
#include <iostream>
#include <string>
#include "stdafx.h"


// awesome headers
#include "HealthPotion.h"



Potion::Potion(int level, int quantity)
{
	m_level = level;
	m_giveHealth = 20 * (m_level * m_level);
	m_potionName = "Health Potion";
	m_quantity = quantity;
}


long Potion::returnGiveHealth()
{
	std::cout << m_potionName << " restored " << m_giveHealth << " health.\n";
	return m_giveHealth;
}

void Potion::upgradePotion(int level)
{
	m_level = level;
	m_giveHealth = m_giveHealth * m_level;
}

void Potion::addPotionQuantity(int quantity)
{
	std::cout << "You got " << quantity << " additional health potion(s)!\n";
	m_quantity = m_quantity + quantity;
}

void Potion::removeOnePotion()
{
	m_quantity = m_quantity - 1;
}

int Potion::returnQuantity()
{
	return m_quantity;
}