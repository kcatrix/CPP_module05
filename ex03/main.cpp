#include <iostream>
#include "Intern.hpp"

int main(void)
{
	Intern A;
	
	try {
		Form*	form = A.makeForm("robotomy request", "r2d2");
		delete form;
	} catch (Intern::FormDoesNotExistException &e) {
		std::cout << "Error: " << e.what() << std::endl;	
	}

	try {
		Form*	form = A.makeForm("robotomy test", "r2d2");
		delete form;
	} catch (Intern::FormDoesNotExistException &e) {
		std::cout << "Error: " << e.what() << std::endl;	
	}	
	return (0);
}

