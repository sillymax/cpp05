/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 02:51:15 by ychng             #+#    #+#             */
/*   Updated: 2024/08/12 04:28:08 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

using std::cout;
using std::endl;

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), target("default")
{
	cout << "PresidentialPardonForm constructed with default values" << endl;
}

PresidentialPardonForm::PresidentialPardonForm(const string& target)
	: AForm("PresidentialPardonForm", 25, 5), target(target)
{
	cout << "PresidentialPardonForm constructed with user values" << endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	cout << "PresidentialPardonForm destructed" << endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
	: AForm(src)
{
	cout << "PresidentialPardonForm copied" << endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		cout << "PresidentialPardonForm assigned" << endl;
	}
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (getSignedState())
	{
		if (executor.getGrade() > getGradeToExec())
			throw GradeTooLowException();
		cout << endl;
		cout << target + " has been pardoned by Zaphod Beeblebrox." << endl;
	}
	else
		throw FormNotSigned();
}
