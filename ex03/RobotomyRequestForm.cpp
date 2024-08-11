/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 02:19:40 by ychng             #+#    #+#             */
/*   Updated: 2024/08/12 04:28:34 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;
using std::rand;

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), target("default")
{
	cout << "RobotomyRequestForm constructed with default values" << endl;
}

RobotomyRequestForm::RobotomyRequestForm(const string& target)
	: AForm("RobotomyRequestForm", 72, 45), target(target)
{
	cout << "RobotomyRequestForm contructed with user values" << endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	cout << "RobotomyRequestForm destructed" << endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
	: AForm(src)
{
	cout << "RobotomyRequestForm copied" << endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		cout << "RobotomyRequestForm assigned" << endl;
	}
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (getSignedState())
	{
		if (executor.getGrade() > getGradeToExec())
			throw GradeTooLowException();
		cout << endl;
		cout << "Drrrrrrrr..." << endl;
		if (rand() % 2 == 0)
			cout << target << " has been robotomized." << endl;
		else
			cout << "Robotomy failed." << endl;
	}
	else
		throw FormNotSigned();
}