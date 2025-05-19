/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:13:41 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/18 22:22:36 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << "------------------------------------------------------------" << std::endl;
	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* w = new WrongCat();
	std::cout << w->getType() << " " << std::endl;
	w->makeSound(); //will output the cat sound!
	wrong_meta->makeSound();
	return 0;
}
