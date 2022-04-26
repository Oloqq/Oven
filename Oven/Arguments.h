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
	filesystem::path home_directory;

	// Init
	CLI::App* init;
	std::string template_name = "default";

	// Run
	CLI::App* run;

	class EnvironmentVariableError : public std::exception
	{
	public:
		EnvironmentVariableError(const char* msg) : std::exception(msg) {}
	};
private:
	void get_home_dir();
};

 