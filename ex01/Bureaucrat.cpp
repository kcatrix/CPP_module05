#include "Bureaucrat.hpp"

struct GradeTooHighException : std::exception 
{
  const char* what() const throw() {return "Grade Too High Exception\n";}
};

struct GradeTooLowException : std::exception 
{
  const char* what() const throw() {return "Grade Too Low Exception\n";}
};

Bureaucrat::Bureaucrat( void )
{
	std::cout << "Constructor called" << std::endl;
	return;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) :  _grade(grade), _name(name)
{
	std::cout << "Constructor called" << std::endl;
	try
	{
		if ( grade < 1 )
			throw GradeTooHighException();
		else if( grade > 150 )
			throw GradeTooLowException();
		
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
}

Bureaucrat::Bureaucrat( Bureaucrat const & )
{
	return ;
}

Bureaucrat & Bureaucrat::operator=( Bureaucrat const & cp )
{
	this->_grade = cp._grade;
	this->_name = cp._name;
	return *this;
}

int Bureaucrat::getGrade ( void ) const
{
	return(this->_grade);
}

std::string Bureaucrat::getName( void ) const
{
	return(this->_name);
}

void Bureaucrat::Increment_Grade( void )
{
	try
	{
		if ( this->_grade < 2 )
			throw GradeTooHighException();
		else if( this->_grade > 150 )
			throw GradeTooLowException();
		else
			this->_grade--;	
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
}

void Bureaucrat::Decrement_Grade( void )
{
	try
	{
		if ( this->_grade < 1 )
			throw GradeTooHighException();
		else if( this->_grade > 149 )
			throw GradeTooLowException();
		else
			this->_grade++;	
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
}

void	Bureaucrat::signForm( Form const A ) // Reason a determiner !
{
	if ( A.getSigned() == true )
		std::cout << this->_name << " signed " << A.getName() << std::endl;
	else
	{
		try
    	{
        	if ( A.get_Sign_Grade() < this->getGrade() )
            	throw GradeTooLowException();
			else
				throw GradeTooHighException();
		}
    	catch (std::exception & e)
    	{
        	std::cout << this->_name << " couldn’t sign " << A.getName()
			<< " because " << e.what();
		}
	}
}

std::ostream & operator<<( std::ostream & os, Bureaucrat const & original )
{
	os << original.getName() << ", bureaucrat grade " << original.getGrade();
	return (os);
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Destructor called" << std::endl;
	return;
}

