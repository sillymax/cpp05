/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:45:39 by ychng             #+#    #+#             */
/*   Updated: 2024/08/11 23:56:41 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "Form.hpp"
# include <iostream>

using std::string;
using std::exception;
using std::ostream;

class Form;

class Bureaucrat
{
public:
	class GradeTooHighException : public exception
	{
	public:
		const char* what() const throw()
		{
			return "Grade is too high!";
		}
	};

	class GradeTooLowException : public exception
	{
	public:
		const char* what() const throw()
		{
			return "Grade is too low!";
		}
	};

	Bureaucrat();
	Bureaucrat(const string& name, short grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& src);

	Bureaucrat& operator=(const Bureaucrat& src);

	const string& getName() const;
	short getGrade() const;
	
	void setGrade(short grade);

	void incrementGrade();
	void decrementGrade();
	void signForm(Form& form);
private:
	const string name;
	short grade;
};

ostream& operator<<(ostream& stream, const Bureaucrat& src);

#endif
