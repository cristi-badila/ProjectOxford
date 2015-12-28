#pragma once

#include <vector>

#include "person.h"

class frame_analyzer
{
public:
	frame_analyzer();
	~frame_analyzer();
	
	person get_person(std::vector<short> &frame);
};

