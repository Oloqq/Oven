#pragma once
#include "Arguments.h"
#include <filesystem>

class Program
{
public:
	Program(const Arguments& args,
		    const filesystem::path home);

private:
	const filesystem::path home;
};

