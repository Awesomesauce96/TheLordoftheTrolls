
/*
All general functions go here
foward declarations go in the GeneralFunctions.h header file
*/

// essential stl headers
#include "stdafx.h"
#include "stdafx.h"
#include <iostream>
#include <string>
#include <random>
#include <ctime>

// awesome headers
#include "GeneralFunctions.h"
#include "Person.h"
#include "Player.h"
#include "Monster.h"
#include "Spells.h"

// welcome message displayed at the start of the program and only there
void printWelcomeMessage()
{
	std::cout << "# # # # # # # # # # # # # # # #\n";
	std::cout << "# # # # # # # # # # # # # # # #\n";
	std::cout << "# # Welcome to: # # # # # # # #\n";
	std::cout << "# # The Lord of the Trolls! # #\n";
	std::cout << "# # # # # # # # # # # # # # # #\n";
	std::cout << "# # A game by Awesomesauce  # #\n";
	std::cout << "# # # # # # # # # # # # # # # #\n";
	std::cout << "# # # # # # # # # # # # # # # #\n";
}

// actual game funcetions
bool doYouWantToPlay()
{
	std::cout << "Do you want to play? y - for yes. All other character's to exit.\n";
	while (true)
	{
		char playAnswer;
		std::cin >> playAnswer;
		if (std::cin.fail())
		{
			cinFailHandling();
			continue;
		}
		else if (playAnswer == 'y')
		{
			std::cin.ignore(32767, '\n');
			return true;
		}
		else
		{
			return false;
		}
	}
}

void playGame()
{
	printWelcomeMessage();
	while (doYouWantToPlay())
	{
		Player currentPlayer;
		Player *pointerPlayer = &currentPlayer;
		initiateSpells(pointerPlayer);
		pickAnAction(currentPlayer);
	}
}

void pickAnAction(Player &actionPlayer)
{
	while (actionPlayer.returnAlive())
	{
		std::cout << "Pick an action with a single letter! h - help!\n";
		char action;
		std::cin >> action;
		
		if (std::cin.fail())
		{
			cinFailHandling();
			continue;
		}
		
		std::cin.ignore(32767, '\n');

		switch (action)
		{
			default:
				std::cout << "That was not a valid action!\n";
				break;
			case 'h':
				printPickActionOptions();
				break;
			case 'o':
				actionPlayer.die();
				break;
			case 'p':
				actionPlayer.printPlayerInfo();
				break;
			case 'f':
			{
				Monster currentMonster(actionPlayer.returnLevel());
				playerMonsterFight(actionPlayer, currentMonster);
				break;
			}
			case 'u':
				actionPlayer.drinkPotion();
				break;
			case 't':
				actionPlayer.printSpells();
				break;
		}
	}
}

void printPickActionOptions()
{
	std::cout << "h - will show you this menu.\n";
	std::cout << "o - will suicide your character.\n";
	std::cout << "p - will print your character's information.\n";
	std::cout << "f - will find a random enemy monster to fight.\n";
	std::cout << "u - will drink a health potion.\n";
	std::cout << "t - will print your current spells\n";
}

// fight functions

void playerMonsterFight(Player &fightPlayer, Monster &fightMonster)
{
	while (fightPlayer.returnAlive() && fightMonster.returnAlive())
	{
		std::cout << "You are in combat! What will you do?!\n";
		char fightAction;
		std::cin >> fightAction;

		if (std::cin.fail())
		{
			cinFailHandling();
			continue;
		}

		std::cin.ignore(32767, '\n');
		
		switch (fightAction)
		{
			default:
				std::cout << "That was not a valid action!\n";
				break;
			case 'a':
				fightPlayer.subHealthPoints(fightMonster.returnDamagePoints());
				fightMonster.subHealthPoints(fightPlayer.returnDamagePoints());
				break;
			case 'd':
				fightMonster.printMonsterInfo();
				break;
			case 'p':
				fightPlayer.printPlayerInfo();
				break;
			case 'h':
				printFightOptions();
				break;
			case 'u':
				fightPlayer.drinkPotion();
				fightPlayer.subHealthPoints(fightMonster.returnDamagePoints());
				break;
			case 't':
				fightPlayer.printSpells();
				break;
			case 'r':
				fightMonster.subHealthPoints(fightPlayer.returnDamagePointsSpell());
				fightPlayer.subHealthPoints(fightMonster.returnDamagePoints());
				break;
		}
		if (!fightMonster.returnAlive())
		{
			std::cout << "You are victorious!\n";
			fightPlayer.addExperience(fightMonster.returnGiveExperience());
			fightPlayer.rewardPotion();
		}
	}
}

void printFightOptions()
{
	std::cout << "h - will show you this menu.\n";
	std::cout << "a - will attack your enemy.\n";
	std::cout << "d - will print monster info.\n";
	std::cout << "p - will print your character's info.\n";
	std::cout << "u - will drink a health potion.\n";
	std::cout << "t - will print your current spells\n";
}


// random Number generators and printers
int getRandomNumber(long min, long max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<long>(rand() * fraction * (max - min + 1) + min);
}

bool getRandomPercent(int percent)
{
	int randNumber = getRandomNumber(1, 100);
	
	if (randNumber <= percent)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void printRandomNumbers()
{
	for (int supcount = 0; supcount < 10; ++supcount)
	{
		for (int count = 0; count < 10; ++count)
		{
			std::cout << getRandomNumber(1, 100) << " ";
		}
		std::cout << "\n";
	}
}

// ERROR HANDLING
void cinFailHandling()
{
	std::cin.clear();
	std::cin.ignore(32767, '\n');
	std::cout << "Oops, something went wrong!\n";
}

// TO BE DELETED, simple function to prevent the program from exiting
void promtBeforeExit()
{
	int x;
	std::cin >> x;
}


// Spell initialising

void initiateSpells(Player * spellPlayer)
{
	Spell *mortalStrike = new Spell(1, PLAYERCLASS_WARRIOR, "Mortal Strike", 15);
	Spell *relentlessStrike = new Spell(2, PLAYERCLASS_WARRIOR, "Relentless Attack", 20);
	Spell *viciousSlam = new Spell(3, PLAYERCLASS_WARRIOR, "Vicious Slam", 25);
	Spell *cunningStrike = new Spell(4, PLAYERCLASS_ROGUE, "Cunning Strike", 20);
	Spell *backstab = new Spell(5, PLAYERCLASS_ROGUE, "Backstab", 25);
	Spell *kidneyShot = new Spell(6, PLAYERCLASS_ROGUE, "Kindney Shot", 30);
	Spell *frostSpike = new Spell(7, PLAYERCLASS_MAGE, "Frost Spike", 25);
	Spell *arcaneBlast = new Spell(8, PLAYERCLASS_MAGE, "Arcane Blast", 30);
	Spell *pyroblast = new Spell(9, PLAYERCLASS_MAGE, "Pyroblast", 35);


	int playerClass = spellPlayer->returnClass();

	switch (playerClass)
	{
	case PLAYERCLASS_WARRIOR:
		spellPlayer->addSpell(mortalStrike);
		spellPlayer->addSpell(relentlessStrike);
		spellPlayer->addSpell(viciousSlam);
		break;
	case PLAYERCLASS_ROGUE:
		spellPlayer->addSpell(cunningStrike);
		spellPlayer->addSpell(backstab);
		spellPlayer->addSpell(kidneyShot);
		break;
	case PLAYERCLASS_MAGE:
		spellPlayer->addSpell(frostSpike);
		spellPlayer->addSpell(arcaneBlast);
		spellPlayer->addSpell(pyroblast);
		break;
	}
}

