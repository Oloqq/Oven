#include "utils.h"
#include "Program.h"
#include "CLI11.hpp"
#include "Arguments.h"
#include <cstdlib>

using namespace std;

const string line = "Oven.exe init";
int targc;
char **targv = make_argv(line, targc);

int main(int argc, char** argv) 
{
	string bua_path = environment("BUA_PATH");
	if (bua_path == "") {
		print("BUA_PATH environment variable not found");
		return 1;
	}

	Arguments* args;
	try {
		args = new Arguments(targc, targv);
	}
	catch (const CLI::ParseError&) { // using --help raises CallForHelp
		return 0;
	}

	//Program program(*args);

	delete args;

	return 0;
}