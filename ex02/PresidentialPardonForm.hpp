#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include <fstream>
# include <iostream>
# include <stdexcept>
# include "Form.hpp"

class Bureaucrat;

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string target );
		void	task( void ) const;
		PresidentialPardonForm( PresidentialPardonForm const & );
		void execute(Bureaucrat const & executor) const;
		~PresidentialPardonForm( void );

		PresidentialPardonForm & operator=( PresidentialPardonForm const & cp );
};	

#endif
