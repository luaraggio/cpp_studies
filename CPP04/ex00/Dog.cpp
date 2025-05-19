/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:07:47 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/18 22:05:47 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type) {
	this->_type = "Dog";
	std::cout << this->_type << " constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << this->_type << " destructor called" << std::endl;
}

Dog::Dog(const Dog &other) {
	*this = other;
}

Dog& Dog::operator=(const Dog &rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return (*this);
}

void	Dog::makeSound() const {
	std::cout << "Wow Wow!" << std::endl;
}
