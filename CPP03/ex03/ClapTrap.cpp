/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 20:07:30 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/18 18:24:09 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Claptrap " << this->_name << " was constructed" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "Claptrap " << this->_name << " was destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap	ClapTrap:: operator=(const ClapTrap &rhs) {
	std::cout << "ClapTrap assignment operator called" << std::endl;
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string &target) {
	if (this->_energyPoints == 0 || this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " has no hit points or no energy points to attack" << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ","
		" causing " <<  this->_attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (amount >= this->_hitPoints) {
		this->_hitPoints = 0;
		std::cout << "Claptrap " << this->_name << " has no hit points left!" << std::endl;
	}
	else {
		this->_hitPoints -= amount;
	}
	std::cout << "ClapTrap " << this->_name << " takes " << amount
		<< " points of damage. Hit points: " << this->_hitPoints << "." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints == 0) {
		std::cout << "Claptrap " << this->_name << " is out of energy and can't be repaired!" << std::endl;
		return ;
	}
	this->_hitPoints += amount;
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " takes " << amount
		<< " points of repair. Hit points: " << _hitPoints << "." << std::endl;
}
