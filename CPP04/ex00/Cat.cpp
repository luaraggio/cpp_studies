/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 22:09:07 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/17 22:50:10 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(std::string type) : Animal(type) {
	this->_type = "Cat";
	std::cout << this->_type << " constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << this->_type << " destructor called" << std::endl;
}
