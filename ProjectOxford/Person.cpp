#include "person.h"

person::person()
{
	mIsKnown = false;
	mName = "Unknown Person";
}


person::person(string pName, bool pIsKnown)
{
	mIsKnown = pIsKnown;
	mName = pName;
}

person::~person()
{
}

string person::get_name()
{
	return mName;
}

bool person::is_known()
{
	return mIsKnown;
}