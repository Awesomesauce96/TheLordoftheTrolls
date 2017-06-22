#pragma once

#include "Person.h"
#include "HealthPotion.h"

class Player : public Person
{
	long m_experience;
	long m_maxExperience;
	int m_class;
	std::string m_className;
	std::string m_classWeapon;
	Potion m_potion;

public:
	Player();

	std::string Player::getPlayerName();
	int Player::getPlayerClass();
	void Player::printPlayerInfo();
	void Player::levelUp();
	void Player::addExperience(long experience);
	long Player::returnDamagePoints();
	void Player::drinkPotion();
	void Player::rewardPotion();
};


enum ePlayerClass
{
	PLAYERCLASS_WARRIOR = 1,
	PLAYERCLASS_ROGUE = 2,
	PLAYERCLASS_MAGE = 3,
	PLAYERCLASS_MAX
};