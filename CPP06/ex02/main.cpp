/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:51:43 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/09 18:45:37 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

#define RESET "\033[0m"
#define PINK "\033[0;35m"

int main() {
	std::cout << PINK "\n========== TEST ==========" RESET << std::endl;

	// Seed the random number generator using the current time
	// This should only be called once per program execution
	srand(time(NULL));

	Base* p = generate();

	identify(p);
	identify(*p);

	delete p;

	std::cout << PINK "\n======= END OF TEST =======" RESET << std::endl;
	return (0);
}
