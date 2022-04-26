#include "utils.h"
#include "Program.h"
#include "CLI11.hpp"
#include "Arguments.h"
#include <cstdlib>
#include <filesystem>

using namespace std;

const string line = "Oven.exe init run";
int targc;
char **targv = make_argv(line, targc);

int main(int argc, char** argv) 
{	
	cout << filesystem::current_path();
	
	string bua_path_s = environment("BUA_PATH");
	if (bua_path_s == "") {
		print("BUA_PATH environment variable not found");
		return 1;
	}
	filesystem::path bua_path = bua_path_s;

	Arguments* args;
	try {
		args = new Arguments(targc, targv);
	}
	catch (const CLI::ParseError&) { // using --help raises CallForHelp
		return 0;
	}
	catch(const ArgumentSyntaxError& error) {
		cout << error;
		return error.checksum;
	}

	Program program(*args, bua_path);

	delete args;
	return 0;
}