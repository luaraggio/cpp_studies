/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:07:47 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/22 18:23:04 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	this->_type = "Dog";
	this->brain = new Brain;
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) {
	this->_type = other._type;
	this->brain = new Brain(*other.brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &rhs) {
	if (this != &rhs) {
		Animal::operator=(rhs);
		delete brain;
		brain = new Brain(*rhs.brain);
	}
	std::cout << "Dog assignment operator called" << std::endl;
	return (*this);
}

Dog::~Dog() {
	delete this->brain;
	std::cout << this->_type << " destructor called" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Wow Wow!" << std::endl;
}

void Dog::setBrainIdeas(int index, const std::string& idea) {
	brain->setIdeas(index, idea);
}

std::string Dog::getBrainIdeas(int index) const {
	return brain->getIdeas(index);
}

