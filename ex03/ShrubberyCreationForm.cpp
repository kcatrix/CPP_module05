#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: Form::Form("shrubbery creation", 145, 137), _target(target)
{ }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & copy)
	: Form::Form(copy), _target(copy.getTarget())
{ }

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{ }

void	ShrubberyCreationForm::execute(const Bureaucrat & executor) const
{
	std::fstream file;
	
	if (executor.getGrade() > this->getGradeToExec())
		throw Form::GradeTooLowException();
	if (!this->isSigned())
		throw Form::NotSignedException();

	file.open((std::string) this->_target + "_shrubbery", std::ios::out);
	file << "   w     w\n  www   www\n wwwww wwwww\n   w     w\n";
	file.close();
}

std::string	ShrubberyCreationForm::getTarget(void) const
{ return (this->_target); }

void	ShrubberyCreationForm::setTarget(std::string & target)
{ this->_target = target; }

ShrubberyCreationForm	*ShrubberyCreationForm::clone(std::string target) const
{ return (new ShrubberyCreationForm(target)); }
