#ifndef SHEUBBERYCREATIONFORM_HPP
# define SHEUBBERYCREATIONFORM_HPP

# include <string>
# include <fstream>
# include <iostream>
# include <stdexcept>
# include "Form.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string target );
		void	task( void ) const;
		ShrubberyCreationForm( ShrubberyCreationForm const & );
		void execute(Bureaucrat const & executor) const;
		~ShrubberyCreationForm( void );

		ShrubberyCreationForm & operator=( ShrubberyCreationForm const & cp );
};	

#endif
