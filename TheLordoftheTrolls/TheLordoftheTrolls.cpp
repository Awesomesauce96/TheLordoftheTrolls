/*TheLordoftheTrolls.cpp : Defines the entry point for the console application.

# # # # # # # # # # # # # # # # # 
# # Written by: Awesomesauce  # #
# # # # # # # # # # # # # # # # #
*/

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
	srand(static_cast<unsigned int>(time(0)));

	playGame();

    return 0;
}

