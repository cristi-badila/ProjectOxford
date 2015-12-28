#include "project_oxford.h"

int main(int argc, char *argv[])
{	
	console_logger logger;
	
	logger.log("Welcome to ProjectOxford");
	
	frame_captor frameCaptor;
	frame_analyzer frameAnalyzer;	
	
	while (true)
	{
		logger.log("Sleeping");
		this_thread::sleep_for(chrono::milliseconds(1000));
		logger.log("Capturing frame");
		auto frame = frameCaptor.capture();
		logger.log("Analyzing frame");
		auto person = frameAnalyzer.get_person(frame);
		auto message = person.is_known()
			? "Welcome " + person.get_name()
			: "No known person identified";
		logger.log(message);
	}
	return 0;
}