#include "console_logger.h"

using namespace std;

console_logger::console_logger()
{
}


console_logger::~console_logger()
{
}

void console_logger::log(string message)
{
	auto timestamp = chrono::system_clock::now();
	auto arithmetic_timestamp = chrono::system_clock::to_time_t(timestamp);
	auto string_timestamp = string(ctime(&arithmetic_timestamp));
	string_timestamp.erase(string_timestamp.length() - 1);
	
	cout << string_timestamp << ":" << message << endl;
}