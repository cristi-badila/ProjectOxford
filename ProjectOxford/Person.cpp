#include "Person.h"

Person::Person()
{
	IsKnown = false;
	Name = "Unknown Person";
}


Person::~Person()
{
}

std::string Name;
bool IsKnown;