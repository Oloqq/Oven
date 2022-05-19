#pragma once
#include <string>

class CorruptedHome : public std::exception
{
public:
	CorruptedHome(const std::string msg) : std::exception(msg.c_str()) {}
};

class BadInput: public std::exception
{
public:
	BadInput(const std::string msg) : std::exception(msg.c_str()) {}
};