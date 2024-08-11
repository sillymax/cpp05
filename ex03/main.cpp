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
#include "Intern.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::exception;

int main()
{
	try
	{
		Bureaucrat max("Max", 1);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "House");
		cout << *rrf;
		max.signForm(*rrf);
		cout << *rrf;
		rrf->execute(max);
		delete rrf;
	}
	catch (const exception& e)
	{
		cout << endl;
		cout << e.what() << endl;
	}
}