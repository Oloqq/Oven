#include "CLI11.hpp"
#include "utils.h"
#include <iostream>
#include "Arguments.h"

Arguments::Arguments(int argc, char** argv)
{	
	CLI::App app{ "Bua oven" };

	app.add_option("-f,--tempfile", filename, "A help string");
	app.add_option("-d,--tempint", bruh, "chlopie");

	CLI::App* init = app.add_subcommand("init", "Initialize a new project");
	CLI::App* run  = app.add_subcommand("run",  "Run");
	
	try {
		(app).parse((argc), (argv));
	}
	catch (const CLI::ParseError& e) {
		app.exit(e);
		throw e;
	}
	
	unsigned int checksum = 0;
	if (init->parsed()) {
		checksum += Verb::init;
	}
	if (run->parsed()) {
		checksum += Verb::run;
	}

	throw_on_conflict(checksum);

	working_directory = filesystem::current_path();
}

void Arguments::throw_on_conflict(unsigned int checksum) const
{
	switch (checksum) {
	case Verb::run + Verb::init:
		throw ArgumentSyntaxError("Can't init and run", checksum);
	default:
		break;
	}
}

