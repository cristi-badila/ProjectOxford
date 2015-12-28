#include "frame_captor.h"

frame_captor::frame_captor()
{	
}


frame_captor::~frame_captor()
{
}

std::vector<short> frame_captor::capture()
{
	std::vector<short> bytes;
	bytes.push_back(10);
	
	return bytes;
}