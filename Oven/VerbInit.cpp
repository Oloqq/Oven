#include "VerbInit.h"
#include <filesystem>

using namespace verb;
namespace fs = filesystem;

void verb::init(const Arguments& args)
{
	fs::path template_path = "C:\\Bua\\Lua\\templates\\default";

	fs::copy(template_path, args.working_directory,
		fs::copy_options::recursive 
		| fs::copy_options::skip_existing);
}