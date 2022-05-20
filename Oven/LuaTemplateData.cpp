#include "LuaTemplateData.h"
#include "json.hpp"
#include <iostream>
#include "Exceptions.hpp"

const Version LuaTemplateData::Dependency::newest_version = "newest";

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
	lib_rel_path = cfg_lib_path;

	// Dependency list
	for (auto& dep : config["lib"]["list"]) {
		dependencies.push_back({ dep.value("name", ""), dep.value("version", "newest")});
	}
}