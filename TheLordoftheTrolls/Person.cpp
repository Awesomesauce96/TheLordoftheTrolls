// essential headers
#include <string>
#include "stdafx.h"
#include <iostream>

// awesome headers
#include "GeneralFunctions.h"
#include "Person.h"

Person::Person(std::string name, long hp) :
	m_name{ name }, m_healthPoints{ hp }
{

}

