/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 11:17:22 by lraggio           #+#    #+#             */
/*   Updated: 2025/12/30 10:53:40 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Form.hpp"

# define RESET   "\033[0m"
# define PINK    "\033[0;35m"
# define RED     "\033[0;31m"
# define GREEN   "\033[0;32m"
# define BLUE    "\033[0;34m"

int main()
{
	std::cout << PINK "========== TESTING BUREAUCRAT ==========" RESET << std::endl;

	std::cout << "Test 1: Valid Bureaucrat" << std::endl;
	try {
		Bureaucrat a("Luara", 42);
		std::cout << GREEN "OK: " RESET << a << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED "Exception: " RESET << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Test 2: Invalid Bureaucrat (grade too high)" << std::endl;
	try {
		Bureaucrat b("Evaluator", 0);
	}
	catch (std::exception &e) {
		std::cout << RED "Exception: " RESET << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Test 3: Increment grade overflow" << std::endl;
	try {
		Bureaucrat c("Top", 1);
		c.incrementGrade();
	}
	catch (std::exception &e) {
		std::cout << RED "Exception: " RESET << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Test 4: Decrement grade overflow" << std::endl;
	try {
		Bureaucrat d("Bottom", 150);
		d.decrementGrade();
	}
	catch (std::exception &e) {
		std::cout << RED "Exception: " RESET << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Test 5: Assignment operator" << std::endl;
	try {
		Bureaucrat e("Ana", 50);
		Bureaucrat f("Joaquina", 75);
		std::cout << "Before assignment: " << f << std::endl;
		f = e;
		std::cout << "After assignment:  " << f << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED "Exception: " RESET << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << PINK "========== TESTING FORM ==========" RESET << std::endl;

	std::cout << "Test 6: Valid Form" << std::endl;
	try {
		Form formA("Contract", 50, 25);
		std::cout << GREEN "OK: " RESET << formA << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED "Exception: " RESET << e.what() << std::endl;
	}

	std::cout << "Test 7: Invalid Form (grade too high)" << std::endl;
	try {
		Form formB("InvalidHigh", 0, 10);
	}
	catch (std::exception &e) {
		std::cout << RED "Exception: " RESET << e.what() << std::endl;
	}

// 	std::cout << "Test 8: Invalid Form (grade too low)" << std::endl;
// 	try {
// 		Form formC("InvalidLow", 10, 200);
// 	}
// 	catch (std::exception &e) {
// 		std::cout << RED "Exception: " RESET << e.what() << std::endl;
// 	}
// 	std::cout << std::endl;

// 	std::cout << PINK "========== TESTING SIGNING FORMS ==========" RESET << std::endl;

// 	std::cout << "Test 9: Successful signing" << std::endl;
// 	try {
// 		Bureaucrat boss("Boss", 1);
// 		Form contract("TopSecret", 10, 5);

// 		std::cout << BLUE "Before signing: " RESET << contract << std::endl;
// 		boss.signForm(contract);
// 		std::cout << BLUE "After signing:  " RESET << contract << std::endl;
// 	}
// 	catch (std::exception &e) {
// 		std::cout << RED "Exception: " RESET << e.what() << std::endl;
// 	}
// 	std::cout << std::endl;

// 	std::cout << "Test 10: Failed signing (grade too low)" << std::endl;
// 	try {
// 		Bureaucrat intern("Intern", 150);
// 		Form contract("Confidential", 10, 5);

// 		std::cout << BLUE "Before signing: " RESET << contract << std::endl;
// 		intern.signForm(contract);
// 		std::cout << BLUE "After signing:  " RESET << contract << std::endl;
// 	}
// 	catch (std::exception &e) {
// 		std::cout << RED "Exception: " RESET << e.what() << std::endl;
// 	}
// 	std::cout << std::endl;

	std::cout << PINK "========== END OF TESTS ==========" RESET << std::endl;
	return (0);
}
