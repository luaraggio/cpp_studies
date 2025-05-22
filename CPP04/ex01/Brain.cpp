/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 22:27:26 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/22 17:55:29 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = other.ideas[i];
	}
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& rhs) {
	if (this != &rhs) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = rhs.ideas[i];
		}
	}
	std::cout << "Brain copy assignment operator called" << std::endl;
	return (*this);
}

void	Brain::setIdeas(int index, const std::string& idea) {
	if (index >= 0 && index < 100) {
		this->ideas[index] = idea;
	}
}

std::string Brain::getIdeas(int index) const {
	if (index >= 0 && index < 100) {
		return (this->ideas[index]);
	}
	std::cout << "error: invalid index." << std::endl;
	return "";
}
