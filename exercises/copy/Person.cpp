/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Person.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 23:35:47 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/15 00:04:00 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Person.hpp"

/*Person::Person(): _name("Empty") {
	std::cout << "Default constructor called" << std::endl;
}*/

Person::Person(const std::string &name): _name(name) {
	std::cout << "Constructor called for " << _name << std::endl;
}

Person::~Person() {
	std::cout << "Destructor called" << std::endl;
}

std::string	Person::getName() const
{
	return (this->_name);
}

void	Person::setName(const std::string &name)
{
	this->_name = name;
}
