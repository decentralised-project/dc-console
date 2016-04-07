#include <iostream>
#include <cstdlib>

int main(int argc, char** argv)
{

#if WIN32
	std::system("cls");
#else
	std::system("clear");
#endif

	std::cout << "... dc-console v1.0 ..." << std::endl;
	return 0;
}