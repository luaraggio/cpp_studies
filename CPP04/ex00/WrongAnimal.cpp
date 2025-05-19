/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:04:20 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/18 22:22:04 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	this->_type = "Default";
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	*this = other;
}

WrongAnimal WrongAnimal::operator=(const WrongAnimal &rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return (*this);
}

std::string	WrongAnimal::getType() const{
	return (this->_type);
}

void	WrongAnimal::makeSound() const {
	std::cout << "Wrong Generic sound" << std::endl;
}
