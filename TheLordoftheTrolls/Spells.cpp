#include "stdafx.h"
#include <iostream>
#include <string>


// awesome headers
#include "Spells.h"
#include "Player.h"
#include "GeneralFunctions.h"


Spell::Spell(int spellID, int classID, std::string spellName, long spellDamage)
{
	m_spellID = spellID;
	m_class = classID;
	m_spellName = spellName;
	m_spellDamage = spellDamage;
}


long Spell::returnDamage(int level)
{
	long spellDmg = m_spellDamage * level * level;
	std::cout << m_spellName << " dealt " << spellDmg <<
		" damage!\n";
	return spellDmg;
}

void Spell::printSpell(int level)
{
	long spellDmg = m_spellDamage * level * level;
	std::cout << m_spellName << " does " << spellDmg <<
		" damage!\n";
}

