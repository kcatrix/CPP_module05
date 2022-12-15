#include "RobotomyRequestForm.hpp"

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

RobotomyRequestForm::RobotomyRequestForm( void ) : Form() 
{
	std::cout << "Constructor called" << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : Form(target, 75, 45)
{
	std::cout << "Constructor called" << std::endl;
	return; 
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
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

void RobotomyRequestForm::task( void ) const
{
	srand(time(0));
	if (rand() % 2)
		std::cout << "BRUIT DE PERCEUSE" << std::endl << this->getName() << " a été robotomisé" << std::endl;
	else
		std::cout << "Opération échouée" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &) 
{
	return ;
}

RobotomyRequestForm & RobotomyRequestForm::operator=( RobotomyRequestForm const & )
{
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout << "Destructor called" << std::endl;
	return;
}
