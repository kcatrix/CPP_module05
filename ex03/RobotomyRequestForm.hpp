#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private:
		std::string _target;
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		~RobotomyRequestForm(void);

		RobotomyRequestForm	*clone(std::string target) const;

		void	execute(const Bureaucrat &executor) const;

		std::string	getTarget(void) const;
		void	setTarget(std::string &target);
};
