/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:48:07 by ychng             #+#    #+#             */
/*   Updated: 2024/08/12 00:07:26 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

using std::cout;
using std::endl;

Bureaucrat::Bureaucrat() : name("default"), grade(75)
{
	cout << "Bureaucrat constructed with default values" << endl;
}

Bureaucrat::Bureaucrat(const string& name, short grade) : name(name)
{
	setGrade(grade);
	cout << "Bureaucrat constructed with user values" << endl;
}

Bureaucrat::~Bureaucrat()
{
	cout << "Bureaucrat destructed" << endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : name(src.getName()), grade(src.getGrade())
{
	cout << "Bureaucrat copied" << endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	if (this != &src)
	{
		grade = src.getGrade();
		cout << "Bureaucrat assigned" << endl;
	}
	return *this;
}

ostream& operator<<(ostream& stream, const Bureaucrat& src)
{
	stream << src.getName() + ", bureaucrat grade " << src.getGrade() << "." << endl;
	return stream;
}

const string& Bureaucrat::getName() const
{
	return name;
}

short Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::setGrade(short grade)
{
	if (grade <= 0)
		throw GradeTooHighException();
	else if (grade >= 151)
		throw GradeTooLowException();
	this->grade = grade;
}

void Bureaucrat::incrementGrade()
{
	setGrade(grade + 1);
}

void Bureaucrat::decrementGrade()
{
	setGrade(grade - 1);
}

void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		cout << getName() << " signed " << form.getName() << "." << endl;
	}
	catch (const Form::GradeTooLowException& e)
	{
		cout << getName() << " couldn't sign " << form.getName()
			 << " because grade is too low." << endl;
	}
	catch (const Form::GradeTooHighException& e)
	{
		cout << getName() << " couldn't sign " << form.getName()
			 << " because grade is too high." << endl;
	}
}
