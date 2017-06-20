#pragma once


class Person
{
protected:
	std::string m_name;
	long m_healthPoints;
	long m_maxHealthPoints;
	long m_damagePoints;
	int m_level;

private:
	bool m_alive;

public:
	Person();

	int Person::returnLevel();
	bool Person::returnAlive();
	long Person::returnDamagePoints();
	void Person::subHealthPoints(long damage);
	void Person::die();

};