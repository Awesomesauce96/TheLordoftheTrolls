
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
			return true;
		}
		else
		{
			return false;
		}
	}
}


// random Number generators and printers
int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

bool getRandomPercent(int percent)
{
	int randNumber = getRandomNumber(1, 100);
	
	if (randNumber <= percent)
	{
		std::cout << "SUCCESS!!\n";
		return true;
	}
	else
	{
		std::cout << "FAIL!\n";
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