#pragma once

#include <vector>

#include "person.h"
#include "oxford_client.h"

using namespace std;

class frame_analyzer
{
public:
	frame_analyzer();
	~frame_analyzer();
	
	person get_person(vector<char> pFilePath);
};

