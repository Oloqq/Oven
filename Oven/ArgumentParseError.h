#pragma once
#include <iostream>
#include <fstream>

class ArgumentSyntaxError : public std::exception
{
	friend std::ostream& operator<< (std::ostream& out, ArgumentSyntaxError err);
public:
	ArgumentSyntaxError(const std::string& msg, unsigned int checksum)
		: std::exception(msg.c_str()), checksum(checksum)
	{
	}
	unsigned int checksum;
};

