/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 22:04:04 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/22 18:09:03 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	this->_type = "Default";
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &other) {
	*this = other;
}

Animal Animal::operator=(const Animal &rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return (*this);
}

std::string	Animal::getType() const{
	return (this->_type);
}

void	Animal::makeSound() const {
	std::cout << "Generic sound " << std::endl;
}
