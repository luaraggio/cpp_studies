/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:07:53 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/17 22:56:20 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <ctime>

#define MAX_VAL 750
#define RESET	"\033[0m"
#define PINK	"\033[0;35m"
#define RED 	"\033[0;31m"

int	main() {
	std::cout << PINK "========== TESTS ==========" RESET << std::endl;
	std::srand(std::time(NULL));

	std::cout << "Test 1: Creation and value assignment" << std::endl;
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];

	for (int i = 0; i < MAX_VAL; i++) {
		int value = std::rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	std::cout << std::endl;

	std::cout << "Test 2: Copy constructor and assignment operator test" << std::endl;
	{
		Array<int> tmp(numbers);//Copy constructor
		Array<int> test;
		test = tmp; //Operator

		for (int i = 0; i < MAX_VAL; i++) { //
			if (test[i] != numbers[i]) {
				std::cerr << "Copy failed" << std::endl;
				return 1;
			}
		}
	} //Destructors are called here (implicit destructor test)
	std::cout << std::endl;

	std::cout << "Test 3: Out-of-bounds access test" << std::endl;
	try {
		numbers[-1] = 42;
	} catch (const std::exception& e) {
		std::cout << "Exception (negative index): " << e.what() << std::endl;
	}

	try {
		numbers[MAX_VAL] = 42;
	} catch (const std::exception& e) {
		std::cout << "Exception (index == size): " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Test 4: Empty array test" << std::endl;
	Array<int> empty;

	try {
		empty[0] = 1;
	} catch (const std::exception& e) {
		std::cout << RED "Exception (empty array): " RESET << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Test 5: size() method test" << std::endl;
	std::cout << "numbers.size(): " << numbers.size() << std::endl;
	std::cout << "empty.size(): " << empty.size() << std::endl;
	std::cout << std::endl;

	std::cout << "Test 6: Const correctness test" << std::endl;
	const Array<int> constArray(numbers);

	try {
		std::cout << "constArray[0]: " << constArray[0] << std::endl;
		// constArray[0] = 5; // <- isso NÃO deve compilar
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Test 7: Template test with another type (std::string)" << std::endl;
	Array<std::string> strings(3);
	strings[0] = "42";
	strings[1] = "Rio";
	strings[2] = "CPP";

	for (unsigned int i = 0; i < strings.size(); i++) {
		std::cout << strings[i] << std::endl;
	}

	delete[] mirror;
	std::cout << PINK "========== END OF TESTS ==========" RESET << std::endl;

	return (0);
}
