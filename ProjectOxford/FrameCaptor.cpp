#include "FrameCaptor.h"

FrameCaptor::FrameCaptor()
{	
}


FrameCaptor::~FrameCaptor()
{
}

std::vector<short> FrameCaptor::Capture()
{
	std::vector<short> bytes;
	bytes.push_back(10);
	
	return bytes;
}