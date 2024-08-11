/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 03:15:40 by ychng             #+#    #+#             */
/*   Updated: 2024/08/12 04:18:27 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include <string>

using std::string;

class Intern
{
public:
	Intern();
	~Intern();
	Intern(const Intern& src);
	Intern& operator=(const Intern& src);

	AForm* createShruberryForm(const string& target) const;
	AForm* createRobotomyRequestForm(const string& target) const;
	AForm* createPresidentialPardonForm(const string& target) const;

	AForm* makeForm(const string& form, const string& target) const;
};

#endif
