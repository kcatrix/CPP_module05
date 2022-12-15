#include "Bureaucrat.hpp"

struct ooops : std::exception 
{
  const char* what() const throw() {return "GradeTooHightExeption\n";}
};

struct ooops2 : std::exception 
{
  const char* what() const throw() {return "GradeTooLowExeption\n";}
};


Bureaucrat::Bureaucrat( void )
{
	std::cout << "Constructor called" << std::endl;
	return;
}

Bureaucrat::Bureaucrat( std::string name, int grade )
{
	std::cout << "Constructor called" << std::endl;
	try
	{
		if (grade < 1 || grade > 149)
		{
			throw ooops();
		}
		else
		{
			this->_name = name;
			this->_grade = grade;
		}
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
        if (this->_grade < 1 || this->_grade > 149)
        {
            throw ooops();
        }
        else
        {
			this->_grade++;	
        }
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
        if (this->_grade < 1 || this->_grade > 149)
        {
            throw ooops2();
        }
        else
        {
			this->_grade--;	
        }
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
}

std::ostream & operator<<( std::ostream & os, Bureaucrat const & original )
{
	os << original.getName() << ", bureaucrat grade " << original.getGrade();
	return (os);
}

const char* what()
{
	return("non michel");
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Destructor called" << std::endl;
	return;
}

