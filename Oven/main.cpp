#include "utils.h"
#include "Arguments.h"
#include <cstdlib>
#include <filesystem>
#include "VerbInit.h"
#include "VerbRun.h"

using namespace std;

const string line = "Oven.exe init";
int targc;
char **targv = make_argv(line, targc);

int main(int argc, char** argv) 
{		
	Arguments* args;
	args = new Arguments(targc, targv);
	try {
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
	print("Parsed arguments");
	// end temp

	try {
		if (args->run->parsed()) {
			throw NotImplemented("run not implemented");
		}
		if (args->init->parsed()) {
			verb::Init a(*args);
		}
	}
	catch (const CorruptedHome& e) {
		cout << e.what();
		return 1;
	}
	catch (const BadInput& e) {
		cout << e.what();
		return 1;
	}
	catch (const NotImplemented& e) {
		cout << e.what();
		return 2;
	}

	delete args;
	return 0;
}