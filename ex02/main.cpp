/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:46:06 by ychng             #+#    #+#             */
/*   Updated: 2024/08/12 03:02:5 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::exception;

int main()
{
	try
	{
		Bureaucrat max("Max", 145);
		Bureaucrat lucas("Lucas", 130);
		ShrubberyCreationForm shrubberyForm("Home");
		
		cout << endl;
		cout << "Initial Grade!" << endl;
		cout << max;
		max.signForm(shrubberyForm);
		max.executeForm(shrubberyForm);
		lucas.signForm(shrubberyForm);
		lucas.executeForm(shrubberyForm);
		cout << endl;
		
		Bureaucrat rongjie("RongJie", 100);
		Bureaucrat lewis("Lewis", 1);
		RobotomyRequestForm robotomyForm("Clement");

		cout << endl;
		cout << "Initial Grade!" << endl;
		cout << rongjie;
		rongjie.signForm(robotomyForm);
		rongjie.executeForm(robotomyForm);
		lewis.signForm(robotomyForm);
		lewis.executeForm(robotomyForm);
		cout << endl;


		Bureaucrat cheeming("CheeMing", 25);
		Bureaucrat weikeat("WeiKeat", 3);
		PresidentialPardonForm presidentialpardonform("Bailey");
		
		cout << endl;
		cout << "Initial Grade!" << endl;
		cout << cheeming;
		cheeming.signForm(presidentialpardonform);
		cheeming.executeForm(presidentialpardonform);
		weikeat.signForm(presidentialpardonform);
		weikeat.executeForm(presidentialpardonform);
		cout << endl;

	}
	catch (const exception& e)
	{
		cout << endl;
		cout << e.what() << endl;
	}
}