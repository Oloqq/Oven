#pragma once
#include "Arguments.h"
#include "Exceptions.hpp"
#include <filesystem>

class Program
{
public:
	Program(const Arguments& args);

protected:
	const Arguments& args;

	std::filesystem::path get_template_path();
};

