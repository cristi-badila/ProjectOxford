#include "ProjectOxford.h"

using namespace std;

int main(int argc, char *argv[])
{
	cout << "Welcome to ProjectOxford" << endl;
	FrameCaptor frameCaptor;
	FrameAnalyzer frameAnalyzer;
	
	while (true)
	{
		cout << "Sleeping" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << "Capturing frame" << endl;
		auto frame = frameCaptor.Capture();
		cout << "Analyzing frame" << endl;
		auto person = frameAnalyzer.GetPerson(frame);
		if (person.IsKnown)
		{
			cout << "Welcome " << person.Name << endl;
		}
		else
		{
			cout << "No known person identified" << endl;
		}		
	}
	return 0;
}