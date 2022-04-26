#pragma once

#include "Arguments.h"
#include <filesystem>

namespace fs = filesystem;

namespace verb
{
	class Init
	{
	public:
		Init(const Arguments& args);

	private:
		void make_package_json();
		fs::path get_template_path();

		const Arguments& args;
		fs::path template_path = "C:\\Bua\\Lua\\templates\\default";
	};

}