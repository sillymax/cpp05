/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:46:06 by ychng             #+#    #+#             */
/*   Updated: 2024/08/12 00:11:18 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::exception;

int main()
{
	try
	{
		Bureaucrat bureaucrat("Max", 2);

		cout << endl;
		cout << "Inital Grade!" << endl;
		cout << bureaucrat;
		cout << endl;

		bureaucrat.incrementGrade();
		cout << endl;
		cout << "Increment Grade!" << endl;
		cout << bureaucrat;
		cout << endl;

		bureaucrat.decrementGrade();
		cout << endl;
		cout << "Decrement Grade!" << endl;
		cout << bureaucrat;
		cout << endl;

		bureaucrat.decrementGrade();
		cout << endl;
		cout << "Decrement Grade!" << endl;
		cout << bureaucrat;
		cout << endl;

	}
	catch (const exception& e)
	{
		cout << endl;
		cout << e.what() << endl;;
	}
}