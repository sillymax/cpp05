/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:21:34 by ychng             #+#    #+#             */
/*   Updated: 2024/08/12 00:01:26 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <stdexcept>

using std::string;
using std::ostream;
using std::exception;

class Bureaucrat;

class Form
{
public:
	class GradeTooHighException : public exception
	{
	public:
		const char* what() const throw()
		{
			return "Form grade is too high!";
		}
	};

	class GradeTooLowException : public exception
	{
	public:
		const char* what() const throw()
		{
			return "Form grade is too low!";
		}
	};

	Form();
	Form(const string& name, short gradeToSign, short gradeToExec);
	~Form();
	Form(const Form& src);
	Form& operator=(const Form& src);

	const string& getName() const;
	short getGradeToSign() const;
	short getGradeToExec() const;
	bool getSignedState() const;

	void beSigned(Bureaucrat& bureaucrat);
private:
	const string name;
	const short gradeToSign;
	const short gradeToExec;
	bool isSigned;
};

ostream& operator<<(ostream& stream, const Form& src);

#endif
