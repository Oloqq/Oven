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
		void manage_dependencies();
		std::filesystem::path get_template_path();

		fs::path template_path;
	};

}