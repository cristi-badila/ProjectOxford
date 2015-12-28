#pragma once

#include <vector>

class frame_captor
{
public:
	frame_captor();
	~frame_captor();
	
	std::vector<short> capture();
};

