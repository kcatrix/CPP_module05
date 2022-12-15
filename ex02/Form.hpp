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

		virtual void beSigned( Bureaucrat const & A );
		virtual bool getSigned( void ) const ;
		virtual bool resetSigned( void );
		virtual int get_Sign_Grade( void ) const ;
		virtual int get_Exec_Grade( void ) const ;
		virtual std::string getName( void ) const ;
		virtual void execute(Bureaucrat const & executor) const = 0 ;
		virtual void task( void ) const ;
		virtual Form & operator=( Form const & ) ;

	private:
		bool _Signed;
		int const _Sign_Grade;
		int const _Exec_Grade;
		std::string const _name;
};

std::ostream & operator<<( std::ostream & os, Form const & original );

#endif
