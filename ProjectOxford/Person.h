#pragma once

#include <string>

using namespace std;

class person
{
public:
	person();
	person(string pName, bool pIsKnown);
	~person();
	string get_name();
	bool is_known();
private:
	string mName;
	bool mIsKnown;
};

