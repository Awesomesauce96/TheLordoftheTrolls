#pragma once

#include "Player.h"
#include "Person.h"
#include "Monster.h"

void printWelcomeMessage();
void promtBeforeExit();
int getRandomNumber(long min, long max);
void printRandomNumbers();
bool getRandomPercent(int percent);
void cinFailHandling();
bool doYouWantToPlay();
void printPickActionOptions();
void pickAnAction(Player &actionPlayer);
void playGame();
void playerMonsterFight(Player &fightPlayer, Monster &fightMonster);
void printFightOptions();