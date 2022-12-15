#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form( void );
		Form( std::string const name, int const Sign_Grade, int const Exec_Grade);
		Form( Form const &, std::string const name,  int const Sign_Grade, int const Exec_Grade);
		~Form( void );

		Form & operator=( Form const & );
		void beSigned( Bureaucrat const & A );
		bool getSigned( void ) const;
		int get_Sign_Grade( void ) const ;
		int get_Exec_Grade( void ) const ;
		std::string getName( void ) const;

	private:
		bool _Signed;
		int const _Sign_Grade;
		int const _Exec_Grade;
		std::string const _name;
};

std::ostream & operator<<( std::ostream & os, Form const & original );

#endif
