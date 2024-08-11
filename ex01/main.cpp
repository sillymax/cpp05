/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:46:06 by ychng             #+#    #+#             */
/*   Updated: 2024/08/12 00:09:22 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::exception;

int main()
{
	try
	{
		Bureaucrat bureaucrat("Max", 1);
		Form form("NDA", 2, 150);
		// Form badform("NDA", -1, 151);

		cout << endl;
		cout << "Initial Grade!" << endl;
		cout << bureaucrat;
		bureaucrat.signForm(form);
		cout << endl;

		bureaucrat.incrementGrade();
		cout << endl;
		cout << "Increment Grade!" << endl;
		cout << bureaucrat;
		bureaucrat.signForm(form);
		cout << endl;

		bureaucrat.decrementGrade();
		cout << endl;
		cout << "Decrement Grade!" << endl;
		cout << bureaucrat;
		bureaucrat.signForm(form);
		cout << endl;

		bureaucrat.decrementGrade();
		cout << endl;
		cout << "Decrement Grade!" << endl;
		cout << bureaucrat;
		bureaucrat.signForm(form);
		cout << endl;
	}
	catch (const exception& e)
	{
		cout << endl;
		cout << e.what() << endl;
	}
}