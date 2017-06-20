// TheLordoftheTrolls.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <random>
#include <ctime>
#include <iostream>

// awesome headers
#include "GeneralFunctions.h"
#include "Person.h"
#include "Player.h"


int main()
{
	printWelcomeMessage();
	srand(static_cast<unsigned int>(time(0)));

	
	Player currentPlayer;
	
	currentPlayer.printPlayerInfo();
	currentPlayer.addExperience(1000);
	currentPlayer.printPlayerInfo();

	promtBeforeExit();
    return 0;
}

