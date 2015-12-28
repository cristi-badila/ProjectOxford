#pragma once

#include <vector>

class FrameCaptor
{
public:
	FrameCaptor();
	~FrameCaptor();
	
	std::vector<short> Capture();
};

