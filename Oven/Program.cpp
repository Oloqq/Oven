#include "Program.h"
#include "json.hpp"
#include "utils.h"
#include "VerbInit.h"
#include "VerbRun.h"
#include <fstream>

Program::Program(const Arguments& args)
{
	if (args.init->parsed()) {
		verb::Init a(args);
	}

	if (args.run->parsed()) {
		verb::run(args);
	}
	
	//// TODO load in separate function / make a Configuration class
	//using namespace nlohmann; // json library
	//ifstream config_file(home / "config.json");
	//if (!config_file.good()) {
	//	throw exception("config bad"); // TODO make serious exception
	//}
	//json config;
	//config_file >> config;
	//
	//cout << config["working"];
	//cout << config["working"].type_name();
	//cout << config["breaking"];
	//cout << config["breaking"].type_name();

}
