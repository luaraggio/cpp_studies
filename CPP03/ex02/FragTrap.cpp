/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 19:14:31 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/18 14:46:55 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " was constructed" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->_name << " was destroyed" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other._name) {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs) {
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
	std::cout << "FragTrap assignment operator called" << std::endl;
}

void	FragTrap::attack(const std::string& target) {
	if (this->_energyPoints == 0 || this->_hitPoints == 0) {
		std::cout << "FragTrap " << this->_name << " has no hit points or no energy points to attack" << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "FragTrap " << this->_name << " attacks " << target << ","
	" causing " <<  this->_attackDamage << " points of damage!" << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount) {
	if (amount >= this->_hitPoints) {
		this->_hitPoints = 0;
		std::cout << "FragTrap " << this->_name << " has no hit points left!" << std::endl;
	}
	else {
		this->_hitPoints -= amount;
	}
	std::cout << "FragTrap " << this->_name << " takes " << amount
		<< " points of damage. Hit points: " << this->_hitPoints << "." << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints == 0) {
		std::cout << "FragTrap " << this->_name << " is out of energy and can't be repaired!" << std::endl;
		return ;
	}
	this->_hitPoints += amount;
	_energyPoints--;
	std::cout << "FragTrap " << _name << " takes " << amount
		<< " points of repair. Hit points: " << _hitPoints << "." << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->_name << " is requesting a high five! " << std::endl;
}
