/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:26:17 by ychng             #+#    #+#             */
/*   Updated: 2024/08/12 00:03:52 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

using std::cout;
using std::endl;

Form::Form() : name("default"), gradeToSign(75), gradeToExec(75), isSigned(false)
{
	cout << "Form constructed default values" << endl;
}

Form::Form(const string& name, short gradeToSign, short gradeToExec)
	: name(name), gradeToSign(gradeToSign), gradeToExec(gradeToExec), isSigned(false)
{
	if (gradeToSign < 0 || gradeToExec < 0)
		throw GradeTooLowException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooHighException();
	cout << "Form constructed user values" << endl;
}

Form::~Form()
{
	cout << "Form destructed" << endl;
}

Form::Form(const Form& src)
	: name(src.getName()), gradeToSign(src.getGradeToSign()), gradeToExec(src.getGradeToExec()), isSigned(src.getSignedState())
{
	cout << "Form copied" << endl;
}

Form& Form::operator=(const Form& src)
{
	if (this != &src)
	{
		isSigned = src.getSignedState();
		cout << "Form assigned" << endl;
	}
	return *this;
}

ostream& operator<<(ostream& stream, const Form& src)
{
	stream << "Name: " << src.getName() << endl
		   << "gradeToSign: " << src.getGradeToSign() << endl
		   << "gradeToExec: " << src.getGradeToExec() << endl
		   << "isSigned: " << ((src.getSignedState()) ? "true" : "false") << endl;
	return stream;
}

const string& Form::getName() const
{
	return name;
}

short Form::getGradeToSign() const
{
	return gradeToSign;
}

short Form::getGradeToExec() const
{
	return gradeToExec;
}

bool Form::getSignedState() const
{
	return isSigned;
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() < gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}
