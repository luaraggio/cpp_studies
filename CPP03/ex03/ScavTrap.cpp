/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 23:28:29 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/18 18:30:12 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("scavtrap") {
	this->_energyPoints = 50;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->_name << " destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other._name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
	std::cout << "ScavTrap assignment operator called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (_energyPoints == 0 || _hitPoints == 0) {
		std::cout << "ScavTrap " << _name << " has no hit points or no energy points to attack" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " attacks " << target
		<< ", causing " << _attackDamage << " points of damage!" << std::endl;
}


void	ScavTrap::takeDamage(unsigned int amount) {
	if (amount >= this->_hitPoints) {
		this->_hitPoints = 0;
		std::cout << "ScavTrap " << _name << " has no hit points" << std::endl;
	}
	else {
		this->_hitPoints -= amount;
	}
	std::cout << "ScavTrap " << _name << " takes " << amount
		<< " points of damage. Hit points: " << _hitPoints << "." << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints == 0) {
		std::cout << "ScavTrap " << this->_name << " is out of energy and can't be repaired!" << std::endl;
		return ;
	}
	this->_hitPoints += amount;
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " takes " << amount
		<< " points of repair. Hit points: " << _hitPoints << "." << std::endl;
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap: " << this->_name << " is now in Gate keeper mode." << std::endl;
}
