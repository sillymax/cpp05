/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 00:25:21 by ychng             #+#    #+#             */
/*   Updated: 2024/08/12 04:28:47 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShruberryCreationForm.hpp"
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ofstream;

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), target("default")
{
	cout << "Shrubbery form constructed with default values" << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const string& target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	cout << "Shrubbery form constructed with user values" << endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	cout << "Shrubbery form destructed" << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
	: AForm(src)
{
	cout << "Shrubbery form copied" << endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		cout << "Shrubbery form assigned" << endl;
	}
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (getSignedState())
	{
		if (executor.getGrade() > getGradeToExec())
			throw GradeTooLowException();
		ofstream file;
		file.open((target + "_shrubbery").c_str());
		if (file.is_open())
		{
			file << "   /\\   \n";
			file << "  /  \\  \n";
			file << " /____\\ \n";
			file << "   ||   \n";
			file << "   ||   \n";
			file.close();
			cout << executor.getName() << " created " + target + "_shrubbery file." << endl;
		}
	}
	else
		throw FormNotSigned();
}