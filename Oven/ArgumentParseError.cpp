#include "ArgumentParseError.h"

std::ostream& operator<< (std::ostream& out, ArgumentSyntaxError err)
{
	out << err.what() << " (checksum: " << err.checksum << ")\n";
	return out;
}
