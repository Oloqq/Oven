#include "VerbInit.h"
#include "json.hpp"
#include "utils.h"
#include <filesystem>

using namespace verb;
namespace fs = filesystem;

Init::Init(const Arguments& args) : Program(args)
{
	template_path = get_template_path();
	
	fs::copy(template_path, args.working_directory,
		  fs::copy_options::recursive 
		| fs::copy_options::skip_existing);

	manage_dependencies();
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

void verb::Init::manage_dependencies()
{	
	LuaTemplateData template_cfg = LuaTemplateData(template_path / "__template.json");
	fs::path srcdir = args.home_directory / "Lua/lib";
	fs::path dstdir = args.working_directory / template_cfg.lib_rel_path;

	fs::path source;
	string filename;
	for (auto& dep : template_cfg.dependencies) {
		filename = dep.name + ".lua";
		if (dep.version == LuaTemplateData::Dependency::newest_version) {
			source = srcdir / filename;
		}
		else {
			source = srcdir / ("v" + dep.version + " " + filename);
		}
		source = srcdir / filename;
		if (fs::exists(source)) {
			fs::copy(source, dstdir / filename,
				fs::copy_options::overwrite_existing);
		}
		else {
			print("Couldn't find dependency:", source.generic_string());
		}

	}
}
