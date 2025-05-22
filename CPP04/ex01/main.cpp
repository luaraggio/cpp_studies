/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:07:23 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/22 18:47:28 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	std::cout << "----------------------- Firt Tests: constructors and destructors-------------------" << std::endl;
	const Animal* i = new Cat();
	const Animal* j = new Dog();

	std::cout << std::endl;

	delete j;//should not create a leak
	delete i;

	std::cout << std::endl;

	std::cout << "----------------------- Second Tests: creating an array of animals -------------------" << std::endl;

	int	const array_size = 4;
	Animal *animals[array_size];

	std::cout << "Creating dog's array" << std::endl;
	for (int i = 0; i < array_size / 2; i++) {
		animals[i] = new Dog();
		std::cout << std::endl;
	}
	std::cout << "Creating cat's array" << std::endl;
	for (int i = array_size / 2; i < array_size; i++) {
		animals[i] = new Cat();
		std::cout << std::endl;
	}
	std::cout << "Deleting animal's array" << std::endl;
	for (int i = 0; i < array_size; i++) {
		delete animals[i];
		std::cout << std::endl;
	}

	std::cout << "----------------------- Third Tests: testing copies of dogs and cats -------------------" << std::endl;
	std::cout << std::endl;

	Dog dog1;
	dog1.setBrainIdeas(0, "Hi!");
	Dog dog2(dog1);

	std::cout << std::endl;
	std::cout << "dog1 idea[0]: " << dog1.getBrainIdeas(0) << std::endl;
	std::cout << "dog2 idea[0]: " << dog2.getBrainIdeas(0) << std::endl;
	std::cout << std::endl;

	std::cout << "----------------------- Changing the copy message -------------------" << std::endl;

	std::cout << std::endl;
	dog2.setBrainIdeas(0, "Hello!");
	std::cout << "dog1 idea[0]: " << dog1.getBrainIdeas(0) << std::endl;
	std::cout << "dog2 idea[0]: " << dog2.getBrainIdeas(0) << std::endl;
	std::cout << std::endl;
	return 0;
}
