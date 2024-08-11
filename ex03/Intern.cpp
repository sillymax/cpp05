/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 03:16:40 by ychng             #+#    #+#             */
/*   Updated: 2024/08/12 04:23:26 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::invalid_argument;

Intern::Intern()
{
	cout << "Intern constructed" << endl;
}

Intern::~Intern()
{
	cout << "Intern destructed" << endl;
}

Intern::Intern(const Intern& src)
{
	(void)src;
	cout << "Intern copied" << endl;
}

Intern& Intern::operator=(const Intern& src)
{
	(void)src;
	cout << "Intern assigned" << endl;
	return *this;
}

AForm* Intern::createShruberryForm(const string& target) const
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const string& target) const
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const string& target) const
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const string& form, const string& target) const
{
	string names[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	AForm* (Intern::*forms[])(const string&) const = {
		&Intern::createPresidentialPardonForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createShruberryForm
	};
	for (int i = 0; i < 3; i++)
	{
		if (form == names[i])
		{
			AForm* temp = (this->*forms[i])(target);
			cout << "Intern creates " << form << "." << endl;
			return temp;
		}
	}
	throw invalid_argument("Not matching form name.");
}
