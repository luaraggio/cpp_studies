/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 20:07:30 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/17 22:51:22 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Claptrap " << this->_name << " was constructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "Claptrap: " << this->_name << " was destroyed" << std::endl;
}

void	ClapTrap::attack(const std::string &target) {
	if (_energyPoints == 0 || _hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " has no hit points or no energy points to attack" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << this->_name << "attacks " << target << ","
		" causing " <<  _attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (amount >= this->_hitPoints) {
		this->_hitPoints = 0;
		std::cout << " hit points empty for Claptrap " << this->_name << std::endl;
	}
	else {
		this->_hitPoints -= amount;
	}
	std::cout << "ClapTrap " << _name << " takes " << amount
		<< " points of damage. Hit points: " << _hitPoints << "." << std::endl;
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
