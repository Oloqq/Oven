#include "Program.h"
#include "json.hpp"
#include "utils.h"
#include <fstream>

namespace fs = std::filesystem;

Program::Program(const Arguments& args) :
	args{args}
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

fs::path Program::get_template_path()
{
	/*fs::path ret(args.home_directory);
	ret /= "Lua/templates";
	if (!fs::is_directory(ret)) {
		throw CorruptedHome("No templates directory");
	}
	ret /= args.template_name;
	if (!fs::is_directory(ret)) {
		throw BadInput("Template does not exist: " + args.template_name);
	}
	return ret;*/

	return fs::path();
}