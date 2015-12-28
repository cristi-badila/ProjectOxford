#pragma once

#include <vector>
#include <fstream>
#include <istream>

#include "config.h"

using namespace std;

class frame_captor
{
public:
	frame_captor();
	~frame_captor();
	
	std::vector<char> capture();
};

