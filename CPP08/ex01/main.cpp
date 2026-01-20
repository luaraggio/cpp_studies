/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 10:00:29 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/20 14:40:01 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>

int main() {
	std::cout << PINK "============================== BASIC SUBJECT TEST ===========================" RESET << std::endl;

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span:  " << sp.longestSpan() << std::endl;

	std::cout << std::endl;
	std::cout << PINK "======================== TESTING WITH 10.000 NUMBERS ========================" RESET << std::endl;

	Span bigSpan(10000);
	std::srand(std::time(NULL)); //seed

	for (int i = 0; i < 10000; ++i) {
		bigSpan.addNumber(std::rand());
	}

	std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
	std::cout << "Longest span:  " << bigSpan.longestSpan() << std::endl;

	std::cout << std::endl;
	std::cout << PINK "============== TESTING FILL A SPAN USING A RANGE OF ITERATORS  ==============" RESET << std::endl;

	std::vector<int> values;
	for (int i = 0; i < 10; ++i) {
		values.push_back(std::rand() % 100);
	}

	Span rangeSpan(100);
	rangeSpan.addNumber(values.begin(), values.end());

	std::cout << "Shortest span: " << rangeSpan.shortestSpan() << std::endl;
	std::cout << "Longest span:  " << rangeSpan.longestSpan() << std::endl;

	std::cout << std::endl;
	std::cout << PINK "=============================== END OF TESTS ================================" RESET << std::endl;
	return (0);
}
