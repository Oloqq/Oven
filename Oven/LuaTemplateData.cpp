#include "LuaTemplateData.h"
#include "json.hpp"
#include <iostream>
#include "Exceptions.hpp"

LuaTemplateData::LuaTemplateData(const filesystem::path& path)
{
	//using namespace nlohmann; // json library
	//ifstream config_file(path);
	//if (!config_file.good()) {
	//	throw CorruptedTemplate("not found");
	//}
	//json config;
	//config_file >> config;

	//cout << config["lib"];
	//cout << config["lib"].type_name();
	//cout << config["lib.path"];
	//cout << config["lib.path"].type_name();
	//cout << config["lib"]["path"];
	//cout << config["lib"]["path"].type_name();
}