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
	//try {
	//}
	//catch (const CLI::ParseError&) { // using --help raises CallForHelp
	//	return 0;
	//}
	/*catch (const Arguments::EnvironmentVariableError& e) {
		cout << e.what();
		return 1;
	}*/
	// temp override
	/*args->working_directory = filesystem::path("C:\\Bua_testsite");
	print("Parsed arguments");*/
	
	if (args->run->parsed()) {
		print("run");
		verb::run(*args);
	}
	if (args->init->parsed()) {
		print("init");
		verb::Init a(*args);
	}

	try {
		/*if (args->run->parsed()) {
			print("run");
			verb::run(*args);
		}
		if (args->init->parsed()) {
			print("init");
			verb::Init a(*args);
		}*/

	}
	catch (const CorruptedHome& e) {
		cout << e.what();
		return 1;
	}
	catch (const BadInput& e) {
		cout << e.what();
		return 1;
	}

	//delete args;
	return 0;
}