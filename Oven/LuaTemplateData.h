#pragma once
#include <filesystem>
#include <vector>
#include <fstream>

using namespace std;

using Version = string;

class LuaTemplateData
{
public:
	class Dependency
	{
	public:
		const static Version newest_version;

		string name;
		Version version;
	};

	LuaTemplateData(const filesystem::path& path);

	filesystem::path lib_rel_path;
	vector<Dependency> dependencies;
};

