// TheLordoftheTrolls.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <random>
#include <ctime>
#include <iostream>

// awesome headers
#include "GeneralFunctions.h"

int main()
{
	printWelcomeMessage();
	srand(static_cast<unsigned int>(time(0)));

	


	promtBeforeExit();
    return 0;
}

