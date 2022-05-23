#include <iostream>
#include <Conversion.h>

int main(int argc, char* argv[], char* envp[])
{
	std::cout << "Executable itself: " << argv[0] << std::endl;
	std::cout << "File to read: " << argv[1] << std::endl;
	std::cout << "File to export to " << argv[2] << std::endl;

	JsonToObj(argv[1], argv[2]);
}
