/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 11:17:22 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/07 19:06:58 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define RESET "\033[0m"
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define PINK "\033[0;35m"
#define BLUE "\033[0;34m"

int main()
{
	std::cout << PINK "\n========== CPP05 ex02 TESTS ==========\n" RESET << std::endl;

	/* ================= SHRUBBERY ================= */

	std::cout << BLUE "\n[TEST 1] Shrubbery: success\n" RESET;
	try {
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm shrub("home");

		boss.signForm(shrub);
		boss.executeForm(shrub);
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	std::cout << BLUE "\n[TEST 2] Shrubbery: execute without sign\n" RESET;
	try {
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm shrub("garden");

		boss.executeForm(shrub);
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	std::cout << BLUE "\n[TEST 3] Shrubbery: grade too low to execute\n" RESET;
	try {
		Bureaucrat low("Intern", 150);
		ShrubberyCreationForm shrub("park");

		low.signForm(shrub);
		low.executeForm(shrub);
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	/* ================= ROBOTOMY ================= */

	std::cout << BLUE "\n[TEST 4] Robotomy: multiple executions (50%)\n" RESET;
	try {
		Bureaucrat boss("Boss", 1);
		RobotomyRequestForm robo("Bender");

		boss.signForm(robo);
		for (int i = 0; i < 5; i++)
			boss.executeForm(robo);
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	std::cout << BLUE "\n[TEST 5] Robotomy: grade too low to sign\n" RESET;
	try {
		Bureaucrat low("Intern", 150);
		RobotomyRequestForm robo("Wall-E");

		low.signForm(robo);
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	/* ================= PRESIDENTIAL ================= */

	std::cout << BLUE "\n[TEST 6] Presidential: success\n" RESET;
	try {
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Arthur Dent");

		president.signForm(pardon);
		president.executeForm(pardon);
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	std::cout << BLUE "\n[TEST 7] Presidential: execute with insufficient grade\n" RESET;
	try {
		Bureaucrat mid("Manager", 20);
		PresidentialPardonForm pardon("Ford Prefect");

		mid.signForm(pardon);
		mid.executeForm(pardon);
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	std::cout << PINK "\n========== END OF TESTS ==========\n" RESET << std::endl;
	return 0;
}
