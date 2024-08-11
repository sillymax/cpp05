/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:26:17 by ychng             #+#    #+#             */
/*   Updated: 2024/08/12 04:32:39 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>

using std::cout;
using std::endl;

AForm::~AForm()
{
	cout << "AForm destructed" << endl;
}

AForm::AForm(const string& name, short gradeToSign, short gradeToExec)
	: name(name), gradeToSign(gradeToSign), gradeToExec(gradeToExec), isSigned(false)
{
	if (gradeToSign < 0 || gradeToExec < 0)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
	cout << "AForm constructed with user values" << endl;
}

AForm::AForm(const AForm& src)
	: name(src.getName()), gradeToSign(src.getGradeToSign()), gradeToExec(src.getGradeToExec()), isSigned(src.getSignedState())
{
	cout << "AForm copied" << endl;
}

AForm& AForm::operator=(const AForm& src)
{
	if (this != &src)
	{
		isSigned = src.getSignedState();
		cout << "AForm assigned" << endl;
	}
	return *this;
}

ostream& operator<<(ostream& stream, const AForm& src)
{
	stream << "Name: " << src.getName() << endl
		   << "gradeToSign: " << src.getGradeToSign() << endl
		   << "gradeToExec: " << src.getGradeToExec() << endl
		   << "isSigned: " << ((src.getSignedState()) ? "true" : "false") << endl;
	return stream;
}

const string& AForm::getName() const
{
	return name;
}

short AForm::getGradeToSign() const
{
	return gradeToSign;
}

short AForm::getGradeToExec() const
{
	return gradeToExec;
}

bool AForm::getSignedState() const
{
	return isSigned;
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}
