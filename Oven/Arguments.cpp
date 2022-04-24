#include "CLI11.hpp"
#include "utils.h"
#include <iostream>
#include "Arguments.h"

Arguments::Arguments(int argc, char** argv)
{
	CLI::App app{ "Bua oven" };

	string filename = "default";
	app.add_option("-f,--file", filename, "A help string");
	int bruh = 1;
	app.add_option("-d,--dddddupa", bruh, "chlopie");

	CLI::App* init = app.add_subcommand("init", "Initialize a new project");
	
	try {
		(app).parse((argc), (argv));
	}
	catch (const CLI::ParseError& e) {
		app.exit(e);
		throw e;
	}
}