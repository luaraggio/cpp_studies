/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:47:40 by lraggio           #+#    #+#             */
/*   Updated: 2025/08/27 12:29:18 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define RESET	"\033[0m"
#define PINK	"\033[0;35m"
#define RED 	"\033[0;31m"

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
