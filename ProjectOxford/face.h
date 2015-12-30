#pragma once

#include <string>

using namespace std;

class face
{
public:
	face();
	face(string pId);
	~face();
	string get_id();
private:
	string mId;
};