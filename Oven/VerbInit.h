#pragma once

#include "Program.h"
#include "Arguments.h"
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

		fs::path template_path;
	};

}