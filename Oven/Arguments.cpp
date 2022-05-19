#include "CLI11.hpp"
#include "utils.h"
#include <iostream>
#include "Arguments.h"

Arguments::Arguments(int argc, char** argv)
{	
	get_home_dir();
	
	//wszystko sie psuje bo CLI::App parsuje wszystko w destruktorze
	// trzeba by zamienic glowny app na wskaznik i dopiero w
	// destruktorze sie go pozbywac
	CLI::App app{ "Bua oven" };

	working_directory = filesystem::current_path();

	// Init
	init =
		app.add_subcommand("init", "Initialize a new project");
	init->add_option("-t,--template", template_name, "Template of the project");
	
	// Run
	run = app.add_subcommand("run", "Run");

	if (run->parsed()) {
		print("run");
	}
	if (init->parsed()) {
		print("init");
	}

	

	try {
		(app).parse((argc), (argv));
	}
	catch (const CLI::ParseError& e) {
		app.exit(e);
		throw e;
	}

	if (run->parsed()) {
		print("run");
	}
	if (init->parsed()) {
		print("init");
	}
}

void Arguments::get_home_dir()
{
	string bua_path_s = environment("BUA_PATH");
	if (bua_path_s == "") {
		throw EnvironmentVariableError("BUA_PATH environment variable not found");
	}
	home_directory = filesystem::path(bua_path_s);
}
