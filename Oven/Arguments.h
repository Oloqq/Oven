#pragma once
#include <string>
#include <filesystem>
#include "CLI11.hpp"
#include <vector>
#include <iostream>

using namespace std;

class Arguments
{
public:
	Arguments(int argc, char** argv);

	filesystem::path working_directory;

	CLI::App* run;
	CLI::App* init;
};

 