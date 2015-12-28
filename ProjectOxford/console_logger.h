#pragma once

#include <iostream>
#include <string>
#include <chrono>
#include <ctime>

class console_logger
{
public:
	console_logger();
	~console_logger();
	
	void log(std::string message);
};

