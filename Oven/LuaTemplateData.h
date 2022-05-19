#pragma once
#include <filesystem>
#include <vector>
#include <fstream>

using namespace std;

using Version = string;

class LuaTemplateData
{
	class Dependency
	{
		const static Version newest;
	public:
		string name;
		Version version;
	};

public:
	LuaTemplateData(const filesystem::path& path);

	filesystem::path lib_path;
	vector<Dependency> dependencies;
};

