/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:51:43 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/09 17:04:43 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <ctime>

#define RESET "\033[0m"
#define PINK "\033[0;35m"

int main() {
	std::cout << PINK "\n========== TEST ==========" RESET << std::endl;

	// Seed the random number generator using the current time
	// This should only be called once per program execution
	srand(static_cast<unsigned int>(time(0)));

	const int num_objects = 3;
	Base* objects[num_objects];

	// for (int i = 0; i < num_objects; ++i) {
	// 	objects[i] = createRandomClass();
	// 	objects[i]->identify(); // Use the object's functionality
	// }

	// Remember to free dynamically allocated memory
	for (int i = 0; i < num_objects; ++i) {
		delete objects[i];
	}

	std::cout << PINK "\n========== END OF TEST ==========" RESET << std::endl;
	return (0);
}
