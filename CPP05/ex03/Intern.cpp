/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:11:12 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/07 19:36:59 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& rhs) {
	(void)rhs;
	return (*this);
}

Intern::~Intern() {}

AForm* Intern::createShrubbery(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string formTarget) {
	std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (Intern::*creators[3])(std::string) = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};

	for (int i = 0; i < 3; i++) {
		if (formName == names[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*creators[i])(formTarget);
		}
	}

	std::cout << "Intern cannot create form: " << formName << std::endl;
	return NULL;
}
