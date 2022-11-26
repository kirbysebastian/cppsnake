#include <iostream>
#include "application.hpp"

int main()
{
	std::cout << "CPPSNAKE!" << std::endl;
	Application app{"cppsnake"};

	app.run();
	return EXIT_SUCCESS;
}
