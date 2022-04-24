#include "utils.h"
#include "Program.h"
#include "CLI11.hpp"
#include "Arguments.h"

using namespace std;

const string line = "Oven.exe --help";
int targc;
char **targv = make_argv(line, targc);

int main(int argc, char** argv) 
{
	Arguments* args;
	try {
		args = new Arguments(targc, targv);
	}
	catch (const CLI::ParseError&) {
		return 0;                                                                                   \
	}

	Program program(*args);

	return 0;
}