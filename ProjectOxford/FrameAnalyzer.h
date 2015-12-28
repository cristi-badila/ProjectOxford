#pragma once

#include <vector>

#include "Person.h"

class FrameAnalyzer
{
public:
	FrameAnalyzer();
	~FrameAnalyzer();
	Person GetPerson(std::vector<short> &frame);
};

