#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: Form::Form("robotomy request", 72, 45), _target(target)
{ }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & copy)
	: Form::Form(copy), _target(copy.getTarget())
{ }

RobotomyRequestForm::~RobotomyRequestForm(void)
{ }

void	RobotomyRequestForm::execute(const Bureaucrat & executor) const
{
	std::cout << "Bruits de perceuses\n";

	if (executor.getGrade() > this->getGradeToExec())
		throw Form::GradeTooLowException();
	if (!this->isSigned())
		throw Form::NotSignedException();

	srand(time(0));
	if (rand() % 2)
		std::cout << this->getTarget() << " has been robotized" << std::endl;
	else
		std::cout << "Failure trying to robotize " << this->getTarget() << std::endl;
}

std::string	RobotomyRequestForm::getTarget(void) const
{ return (this->_target); }

void	RobotomyRequestForm::setTarget(std::string & target)
{ this->_target = target; }

RobotomyRequestForm	*RobotomyRequestForm::clone(std::string target) const
{ return (new RobotomyRequestForm(target)); }
