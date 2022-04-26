#pragma once
#include "ArgumentParseError.h"
#include <string>
#include <filesystem>
#include <vector>
#include <iostream>

using namespace std;

class Arguments
{
public:
	Arguments(int argc, char** argv);

	
	filesystem::path working_directory;

	// temp
	string filename = "";
	int bruh = 0;
private:
	enum Verb : unsigned int
	{
		init = 1 << 0,
		run  = 1 << 1
	};

	void throw_on_conflict(unsigned int checksum) const;
};

 