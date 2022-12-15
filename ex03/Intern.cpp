#include "Intern.hpp"

Intern::Intern(void)
{
	this->types = new Form*[3];	
	this->types[0] = new ShrubberyCreationForm("null");
	this->types[1] = new RobotomyRequestForm("null");
	this->types[2] = new PresidentialPardonForm("null");
}

Intern::Intern(const Intern & copy)
{
	for (int i = 0; i < 3; i++)
		this->types[i] = copy.types[i]->clone(copy.types[i]->getTarget());
}

Intern::~Intern(void)
{ 
	delete[] this->types;
}

Form	*Intern::makeForm(std::string formName, std::string formTarget)
{
	for (int i = 0; i < 3; i++)
	{
		if (this->types[i]->getName() == formName)
		{
			std::cout << "Intern creates " << this->types[i]->getName() << std::endl;
			return (this->types[i]->clone(formTarget));
		}
	}
	throw Intern::FormDoesNotExistException();
	return (NULL);
}
