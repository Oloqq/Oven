#pragma once

#include "Program.h"
#include "Arguments.h"
#include "LuaTemplateData.h"
#include <filesystem>

namespace fs = filesystem;

namespace verb
{
	class Init : public Program
	{
	public:
		Init(const Arguments& args);

	private:
		void make_package_json();
		std::filesystem::path get_template_path();
		LuaTemplateData read_template_config();

		fs::path template_path;
	};

}