/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 22:09:07 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/22 18:26:05 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	this->_type = "Cat";
	this->brain = new Brain;
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) {
	this->_type = other._type;
	this->brain = new Brain(*other.brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &rhs) {
	if (this != &rhs) {
		Animal::operator=(rhs);
		delete brain;
		brain = new Brain(*rhs.brain);
	}
	std::cout << "Cat assignment operator called" << std::endl;
	return (*this);
}

Cat::~Cat() {
	delete this->brain;
	std::cout << this->_type << " destructor called" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}

void Cat::setBrainIdeas(int index, const std::string& idea) {
	brain->setIdeas(index, idea);
}

std::string Cat::getBrainIdeas(int index) const {
	return brain->getIdeas(index);
}
