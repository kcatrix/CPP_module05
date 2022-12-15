#include "Bureaucrat.hpp"

int main()
{

	Bureaucrat c("jack", 5);
	Bureaucrat b("michel", 148);
	std::cout << b << std::endl;
	b.Increment_Grade();
	b.Increment_Grade();
	std::cout << b << std::endl;
	b.Increment_Grade();
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	for(int i = 0; i != 5; i++)
		c.Decrement_Grade();
	std::cout << c << std::endl;
	c.Decrement_Grade();
	std::cout << c << std::endl;
}
