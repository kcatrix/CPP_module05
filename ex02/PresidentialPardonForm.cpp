#include "PresidentialPardonForm.hpp"

struct GradeTooHighException : std::exception
{
  const char* what() const throw() {return "Grade Too High Exception\n";}
};

struct GradeTooLowException : std::exception
{
  const char* what() const throw() {return "Grade Too Low Exception\n";}
};

struct notSigned : std::exception
{
  const char* what() const throw() {return "not signed\n";}
};
PresidentialPardonForm::PresidentialPardonForm( void ) : Form() 
{
	std::cout << "Constructor called" << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : Form(target, 25, 5)
{
	std::cout << "Constructor called" << std::endl;
	return; 
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (this->getSigned() == true && executor.getGrade() <= this->get_Exec_Grade() && executor.getGrade() <= this->get_Sign_Grade())
			this->task();
		else if (executor.getGrade() > this->get_Exec_Grade() && executor.getGrade() > this->get_Sign_Grade())
			throw GradeTooLowException();
		else if (executor.getGrade() < 1)
			throw GradeTooHighException();
		else
			throw notSigned();
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
}

void PresidentialPardonForm::task( void ) const
{
	std::cout << this->getName() << " a été pardonnée par Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const &)
{
	return ;
}

PresidentialPardonForm & PresidentialPardonForm::operator=( PresidentialPardonForm const & )
{
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout << "Destructor called" << std::endl;
	return;
}
