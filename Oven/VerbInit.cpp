#include "VerbInit.h"
#include "json.hpp"
#include <filesystem>

using namespace verb;
namespace fs = filesystem;

Init::Init(const Arguments& args) : Program(args)
{
	template_path = get_template_path();
	
	fs::copy(template_path, args.working_directory,
		  fs::copy_options::recursive 
		| fs::copy_options::skip_existing);

	LuaTemplateData template_config = read_template_config();
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



fs::path Init::get_template_path()
{
	fs::path ret(args.home_directory);
	ret /= "Lua/templates";
	if (!fs::is_directory(ret)) {
		throw CorruptedHome("No templates directory");
	}
	ret /= args.template_name;
	if (!fs::is_directory(ret)) {
		throw BadInput("Template does not exist: " + args.template_name);
	}
	return ret;

	return fs::path();
}

LuaTemplateData verb::Init::read_template_config()
{	
	return LuaTemplateData(template_path / "__template.json");
}
