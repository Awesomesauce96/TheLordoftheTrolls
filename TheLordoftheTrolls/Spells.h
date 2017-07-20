#pragma once


class Spell
{
	int m_spellID;
	int m_class;
	std::string m_spellName;
	long m_spellDamage;
	int m_spellLevel;

public:
	Spell(int spellID, int classID, std::string spellName, long spellDamage);

	long Spell::returnDamage(int level);
	void Spell::printSpell(int level);

};

