#include "Bureaucrat.hpp"

int main()
{

	Form a("violoneux", 12, 4);
	Bureaucrat c("jack", 5);
	Bureaucrat b("michel", 148);
	Bureaucrat d("sabrinana", 1);

	std::cout << b << std::endl;
	b.Increment_Grade();
	b.Increment_Grade();
	std::cout << b << std::endl;
	b.Increment_Grade();
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	for(int i = 0; i != 3; i++)
		c.Decrement_Grade();
	std::cout << c << std::endl;
	c.Decrement_Grade();
	std::cout << c << std::endl;
	std::cout << b << std::endl;
	a.beSigned(b);
	b.signForm(a); 
	a.beSigned(c);
	c.signForm(a); 
	a.beSigned(d);
	std::cout << a << std::endl;
	d.signForm(a); 
}
