#pragma once

#include "Person.h"
#include "HealthPotion.h"
#include "Spells.h"
#include <vector>

class Player : public Person
{
	long m_experience;
	long m_maxExperience;
	int m_class;
	std::string m_className;
	std::string m_classWeapon;
	Potion m_potion;
	std::vector<Spell*> m_spells;


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
	void Player::addSpell(Spell *spellName);
	int Player::returnClass();
	void Player::printSpells();
	long Player::returnDamagePointsSpell();
	int Player::returnSpellsLength();
};


enum ePlayerClass
{
	PLAYERCLASS_WARRIOR = 1,
	PLAYERCLASS_ROGUE = 2,
	PLAYERCLASS_MAGE = 3,
	PLAYERCLASS_MAX
};