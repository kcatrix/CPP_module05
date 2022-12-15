#include "ShrubberyCreationForm.hpp"

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

ShrubberyCreationForm::ShrubberyCreationForm( void ) : Form() 
{
	std::cout << "Constructor called" << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : Form(target, 145, 137)
{
	std::cout << "Constructor called" << std::endl;
	return; 
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
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

void ShrubberyCreationForm::task( void ) const
{
	std::string filename;
	filename += this->getName();
	filename += "_shrubbery";
	std::ofstream _target( filename );
	_target <<  "        tt                                                                                       tttt                                                                                     tttttt                                                                                      || " ; 
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &)
{
	return ;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & )
{
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << "Destructor called" << std::endl;
	return;
}
