/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:21:34 by ychng             #+#    #+#             */
/*   Updated: 2024/08/12 03:08:42 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <stdexcept>

using std::string;
using std::ostream;
using std::exception;

class Bureaucrat;

class AForm
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

	class FormNotSigned : public exception
	{
	public:
		const char* what() const throw()
		{
			return "Form is not signed!";
		}
	};

	AForm();
	virtual ~AForm();
	AForm(const string& name, short gradeToSign, short gradeToExec);
	AForm(const AForm& src);
	AForm& operator=(const AForm& src);

	const string& getName() const;
	short getGradeToSign() const;
	short getGradeToExec() const;
	bool getSignedState() const;

	void beSigned(Bureaucrat& bureaucrat);
	virtual void execute(const Bureaucrat& executor) const = 0;
private:
	const string name;
	const short gradeToSign;
	const short gradeToExec;
	bool isSigned;
};

ostream& operator<<(ostream& stream, const AForm& src);

#endif
