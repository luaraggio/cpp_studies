/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 11:17:22 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/07 19:44:45 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"

#define RESET "\033[0m"
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define PINK "\033[0;35m"
#define BLUE "\033[0;34m"

int main() {
	std::cout << PINK "\n========== CPP05 ex02 TESTS ==========" RESET << std::endl;
	Intern intern;
	AForm* form;

	std::cout << BLUE "\n--- TEST 1: Valid form ---\n" RESET;
	form = intern.makeForm("robotomy request", "Bender");
	if (form) {
		Bureaucrat boss("Boss", 1);
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}

	std::cout << BLUE "\n--- TEST 2: Another valid form ---\n" RESET;
	form = intern.makeForm("shrubbery creation", "home");
	if (form) {
		Bureaucrat boss("Boss", 1);
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}
	std::cout << std::endl;

	std::cout << BLUE "\n--- TEST 3: Invalid form ---\n" RESET;
	form = intern.makeForm("coffee making", "office");
	if (!form) {
		std::cout << RED "Form creation failed as expected" RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << PINK "\n========== END OF TESTS ==========" RESET << std::endl;
	return 0;
}
