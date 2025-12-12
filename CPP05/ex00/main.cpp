/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:47:40 by lraggio           #+#    #+#             */
/*   Updated: 2025/11/24 15:20:37 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define RESET	"\033[0m"
#define PINK	"\033[0;35m"
#define RED 	"\033[0;31m"

/**
 * @brief Entry point for testing the Bureaucrat class.
 *
 * This main function demonstrates:
 * - Correct creation of a Bureaucrat
 * - Handling of invalid grades using exceptions
 * - Incrementing and decrementing grades
 * - Behavior at grade boundaries (1 and 150)
 * - Copy assignment operator validation
 *
 * Colored output is used purely for visual clarity in the terminal:
 * - PINK highlights the test section header.
 * - RED highlights caught exceptions.
 *
 * The tests are divided as follows:
 *  Test 1: Valid construction.
 *  Test 2: Construction with an invalid grade (too high).
 *  Test 3: Incrementing grades until an exception is triggered.
 *  Test 4: Decrementing grades beyond the allowed limit.
 *  Test 5: Testing the assignment operator.
 *
 * @return int Exit status.
 */

int main() {
	std::cout << PINK "Testing Bureaucrat Exceptions:\n" RESET << std::endl;

	std::cout << "Test 1:" << std::endl;
	try {
		Bureaucrat a("Luara", 42);
		std::cout << a << std::endl;
	}
	catch (std::exception& e) {
		std::cout << 	RED "Exception Caught: " RESET << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Test 2:" << std::endl;
	try {
		Bureaucrat b("Evaluator", 0);
		std::cout << b << std::endl;
	}
	catch (std::exception& e) {
		std::cout << 	RED "Exception Caught: " RESET << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Test 3:" << std::endl;
	try {
		Bureaucrat i("Intermediate 1", 2);
		std::cout << i << std::endl;
		i.incrementGrade();
		std::cout << "After incrementing: " << i << std::endl;
		i.incrementGrade();
	}
	catch (std::exception& e) {
		std::cout << 	RED "Exception Caught: " RESET << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Test 4: " << std::endl;
	try {
		Bureaucrat d("Intermediate 2", 150);
		std::cout << d << std::endl;
		d.decrementGrade();
	}
	catch (std::exception& e) {
		std::cout << 	RED "Exception Caught: " RESET << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Test 5: " << std::endl;
	try {
		Bureaucrat e("Ana", 50);
		Bureaucrat f("Joaquina", 75);
		std::cout << "Before f = e: " << f << std::endl;
		f = e;
		std::cout << "After f = e: " << f << std::endl;
	}
	catch (std::exception& e) {
		std::cout << 	RED "Exception Caught: " RESET << e.what() << std::endl;
	}
}
