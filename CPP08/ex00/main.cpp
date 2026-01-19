/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 10:00:29 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/18 16:11:05 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "cstdlib"
#include "ctime"
#include <list>

int main() {
	std::cout << PINK "================= TESTS ================" RESET << std::endl;

	std::srand(std::time(NULL)); //Seed do gerador

	std::cout << BLUE "Testing with Vectores" RESET << std::endl;
	std::vector<int> v(10); //Cria vector de tamanho 10

	std::cout << "Vector contents: ";
	for (size_t i = 0; i < v.size(); i++) { //Preenche vector com números aleatórios de 0 a 9 e printa
		v[i] = std::rand() % 10;
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;

	int to_find = std::rand() % 10; //Gera número aleatório para buscar
	std::cout << "Test 1: trying to find '" << to_find << "' in vector" << std::endl;

	try {
		std::vector<int>::iterator it = easyfind(v, to_find);
		std::cout << "Found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED "Exception: " RESET << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << BLUE "Testing with List" RESET << std::endl;
	std::list<int> l;
    std::cout << "List contents: ";
    for (int i = 0; i < 10; i++) {
		int value = std::rand() % 10;
		l.push_back(value);
		std::cout << value << " ";
	}
	std::cout << std::endl;

	to_find = std::rand() % 10;
	std::cout << "List test: trying to find '" << to_find << "' in list" << std::endl;

	try {
		std::list<int>::iterator it = easyfind(l, to_find);
		std::cout << "Found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED "Exception: " RESET << e.what() << std::endl;
	}

	std::cout << PINK "============= END OF TESTS =============" RESET << std::endl;
	return (0);
}
