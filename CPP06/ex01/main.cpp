/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:51:43 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/09 15:39:54 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

#define RESET "\033[0m"
#define PINK "\033[0;35m"

int main() {
	std::cout << PINK "\n========== TEST ==========" RESET << std::endl;

	Data data;

	data.name = "Luara";
	data.value = 42;

	uintptr_t raw = Serializer::serialize(&data); //Converte ponteiro para inteiro

	Data* ptr = Serializer::deserialize(raw); //Converte inteiro de volta para ponteiro

	std::cout << "Original pointer: " << &data << std::endl;
	std::cout << "Serialized (uintptr_t): " << raw << std::endl;
	std::cout << "Deserialized pointer: " << ptr << std::endl;

	if (ptr == &data) {
		std::cout << "Pointers match!" << std::endl;
	}
	else {
		std::cout << "Pointers do NOT match!" << std::endl;
	}

	std::cout << "Value via deserialized pointer: " << ptr->value << std::endl;
	std::cout << "Name via deserialized pointer: " << ptr->name << std::endl;
	std::cout << PINK "\n========== END OF TEST ==========" RESET << std::endl;
	return (0);
}
