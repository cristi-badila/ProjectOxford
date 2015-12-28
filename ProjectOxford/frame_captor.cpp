#include "frame_captor.h"
#include "console_logger.h"

frame_captor::frame_captor()
{	
}


frame_captor::~frame_captor()
{
}

vector<char> frame_captor::capture()
{
	console_logger logger;
	
	vector<char> fileBytes;
	ifstream photoFile(PHOTO_FILE_PATH, ios::in | ios::binary | ios::ate);	
	if (photoFile.is_open())
	{
		auto size = photoFile.tellg();
		fileBytes = vector<char>(size);
		photoFile.seekg(0, ios::beg);
		photoFile.read(&fileBytes[0], size);
		photoFile.close();		
		logger.log(string("Read file ") + string(PHOTO_FILE_PATH));
	}
	else
	{
		logger.log(string("Could not open ") + string(PHOTO_FILE_PATH));
	}

	return fileBytes;	
}