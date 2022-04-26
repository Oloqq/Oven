#include "VerbInit.h"
#include "json.hpp"
#include <filesystem>

using namespace verb;
namespace fs = filesystem;

Init::Init(const Arguments& args) :
	args{args}
{
	fs::copy(template_path, args.working_directory,
		  fs::copy_options::recursive 
		| fs::copy_options::skip_existing);
}

fs::path verb::Init::get_template_path()
{
	return fs::path();
}

void Init::make_package_json()
{
	//// TODO load in separate function / make a Configuration class
	//using namespace nlohmann; // json library
	//ifstream config_file(folder / "config.json");
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
