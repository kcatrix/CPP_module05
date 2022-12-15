#include "Form.hpp"

struct GradeTooHighException : std::exception
{
  const char* what() const throw() {return "Grade Too High Exception\n";}
};

struct GradeTooLowException : std::exception
{
  const char* what() const throw() {return "Grade Too Low Exception\n";}
};

Form::Form( void ) : _Signed(false), _Sign_Grade(0), _Exec_Grade(0), _name("default")
{
	std::cout << "Constructor called" << std::endl;
	
	try
	{
		if ( this->_Exec_Grade < 1 || this->_Sign_Grade < 1)
			throw GradeTooHighException();
		else if ( this->_Exec_Grade > 149 || this->_Sign_Grade > 149)
			throw GradeTooLowException();
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
	return;
}

Form::Form( std::string const name, int const Sign_Grade, int const Exec_Grade) : _Sign_Grade(Sign_Grade), _Exec_Grade(Exec_Grade), _name(name)

{
	std::cout << "Constructor called" << std::endl;
	try
	{
		if ( this->_Exec_Grade < 1 || this->_Sign_Grade < 1)
			throw GradeTooHighException();
		else if ( this->_Exec_Grade > 149 || this->_Sign_Grade > 149)
			throw GradeTooLowException();
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
	return ;
}

Form::Form( Form const &, std::string const name, int const Sign_Grade, int const Exec_Grade) : _Sign_Grade(Sign_Grade), _Exec_Grade(Exec_Grade), _name(name)
{
	return ;
}

Form & Form::operator=( Form const & )
{
	return *this;
}

void Form::beSigned( Bureaucrat const & A )
{
	this->_Signed = false;
	try
	{
		if ( A.getGrade() > this->_Sign_Grade )
			throw GradeTooLowException(); 
		else if ( A.getGrade() < 1 )
			throw GradeTooHighException();
		else
			this->_Signed = true;
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
}

bool Form::getSigned( void ) const
{
	return this->_Signed;
}

int Form::get_Sign_Grade ( void ) const
{
	return(this->_Sign_Grade);
}

int Form::get_Exec_Grade ( void ) const
{
	return(this->_Exec_Grade);
}

std::string Form::getName( void ) const
{
	return(this->_name);
}

std::ostream & operator<<( std::ostream & os, Form const & original )
{
	os << "Form name : " << original.getName() << ", Sign_Grade : "
		<< original.get_Sign_Grade() << ", Exec_Grade : "
		<< original.get_Exec_Grade() << ", Signed : "
		<< original.getSigned();
	return (os);
}

Form::~Form( void )
{
	std::cout << "Destructor called" << std::endl;
	return;
}
