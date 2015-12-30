#include "face.h"


face::face()
{
	mId = "UNKNOWN";
}

face::face(string pId)
{
	mId = pId;
}


face::~face()
{
}

string face::get_id()
{
	return mId;
}