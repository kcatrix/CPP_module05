#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat( void );
		Bureaucrat( std::string name, int grade );
		Bureaucrat( Bureaucrat const & );
		~Bureaucrat( void );

		Bureaucrat & operator=( Bureaucrat const & cp );
		void signForm( Form const A );
		int getGrade( void ) const ;
		std::string getName( void ) const ;
		void Increment_Grade( void );
		void Decrement_Grade( void );

	private:
		int _grade;
		std::string _name;
};	

std::ostream & operator<<( std::ostream & os, Bureaucrat const & original );

#endif
