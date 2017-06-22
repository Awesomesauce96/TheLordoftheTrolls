#pragma once

#include <string>
#include <iostream>

class Potion
{
private:
	std::string m_potionName;
	long m_giveHealth;
	int m_level;
	int m_quantity;

public:
	Potion() = delete;
	Potion(int level, int quantity);

	long Potion::returnGiveHealth();
	void Potion::upgradePotion(int level);
	void Potion::addPotionQuantity(int quantity);
	void Potion::removeOnePotion();
	int Potion::returnQuantity();
};