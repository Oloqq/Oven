#include "Program.h"
#include "json.hpp"
#include <fstream>
#include "utils.h"

Program::Program(const Arguments& args,
				 const filesystem::path home) :
	home{home}
{
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
