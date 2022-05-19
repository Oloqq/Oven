#include "LuaTemplateData.h"
#include "json.hpp"
#include <iostream>
#include "Exceptions.hpp"

LuaTemplateData::LuaTemplateData(const filesystem::path& path)
{
	using namespace nlohmann; // json library
	ifstream config_file(path);
	if (!config_file.good()) {
		throw CorruptedTemplate("Template not found");
	}
	json config;
	config_file >> config;

	// Lib path
	string cfg_lib_path = config["lib"].value("path", "");
	if (cfg_lib_path == "") {
		throw CorruptedTemplate("Missing lib.path");
	}
	lib_path = path / cfg_lib_path;

	// Dependency list
	for (auto& dep : config["lib"]["list"]) {
		dependencies.push_back({ dep.value("name", ""), dep.value("version", "")});
	}

	//temp
	cout << "RESULTS" << endl;
	cout << lib_path << endl;
	for (Dependency& d : dependencies) {
		cout << d.name << " v" << d.version << endl;
	}

	/*cout << config["lib"] << endl;
	cout << config["lib"].type_name() << endl;
	cout << config["lib"]["path"] << endl;
	cout << config["lib"].value("path", "a") << endl;
	cout << config["lib"]["list"].type_name() << endl;*/
	cout << "END RESULTS" << endl;

}