#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("bob"), _grade(150){}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException(); 
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{ *this = copy; }

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy)
{
	(std::string) this->_name = copy._name;
	this->_grade = copy._grade;
	return (*this);
}

void Bureaucrat::upGrade(void)
{
	if (this->_grade > 1)
		this->_grade--;
	else
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::downGrade(void)
{
	if (this->_grade < 150)
		this->_grade++;
	else
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::executeForm(const Form &form)
{
	form.execute(*this);
	std::cout << this->getName() << " execute " << form.getName() << "\n";
}

std::string	Bureaucrat::getName(void) const
{ return ((std::string) this->_name); }

int	Bureaucrat::getGrade(void) const
{ return (this->_grade); }

std::ostream&	operator<<(std::ostream &out, const Bureaucrat *target)
{
	out << target->getName() << ", bureaucrat grade " << target->getGrade();
	return (out);
}

void	Bureaucrat::signForm(Form *form)
{
	form->beSigned(*this);
	try {
		if (form->isSigned())
			std::cout << this->getName() << " signs " << form->getName() << "\n";
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << this->getName() << " cannot sign because " << e.what() << "\n";
	}
}