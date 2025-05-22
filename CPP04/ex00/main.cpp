/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:13:41 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/22 20:20:18 by lraggio          ###   ########.fr       */
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
	WrongCat cat1;
	cat1.makeSound();
	WrongCat cat2(cat1);
	cat2.makeSound();
	
	std::cout << w->getType() << " " << std::endl;
	w->makeSound(); //will output the cat sound!
	wrong_meta->makeSound();
	delete j;
	delete i;
	delete meta;
	delete wrong_meta;
	delete w;
	return 0;
}
