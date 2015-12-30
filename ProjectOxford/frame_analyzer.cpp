#include "frame_analyzer.h"

frame_analyzer::frame_analyzer()
{
}


frame_analyzer::~frame_analyzer()
{
}

person frame_analyzer::get_person(vector<char> pFrameData)
{
	person person;
	oxford_client client;
	auto face = client.detect_face(pFrameData);
	
	return person;
}