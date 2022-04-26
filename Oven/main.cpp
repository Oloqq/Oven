#include "utils.h"
#include "Program.h"
#include "Arguments.h"
#include <cstdlib>
#include <filesystem>

using namespace std;

const string line = "Oven.exe init";
int targc;
char **targv = make_argv(line, targc);

int main(int argc, char** argv) 
{		
	Arguments* args;
	try {
		args = new Arguments(targc, targv);
	}
	catch (const CLI::ParseError&) { // using --help raises CallForHelp
		return 0;
	}
	catch (const Arguments::EnvironmentVariableError& e) {
		cout << e.what();
		return 1;
	}
	// temp override
	args->working_directory = filesystem::path("C:\\Bua_testsite");

	Program program(*args);

	delete args;
	return 0;
}