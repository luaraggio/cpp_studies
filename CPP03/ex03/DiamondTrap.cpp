/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:02:51 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/18 18:52:45 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*
• Name, which is passed as a parameter to a constructor OK
• ClapTrap::name (parameter of the constructor + "_clap_name" suffix) ok
• Hit points (FragTrap) ok
• Energy points (ScavTrap) ok
• Attack damage (FragTrap) ok
• attack() (ScavTrap)
*/

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"),
	ScavTrap(), FragTrap(), _name(name) {
	std::cout << "DiamondTrap " << this->_name << " constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other._name + "_clap_name"), ScavTrap(), FragTrap(), _name(other._name) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs) {
	if (this != &rhs) {
		ClapTrap::operator=(rhs);
		this->_name = rhs._name;
	}
	return (*this);
	std::cout << "DiamondTrap assignment operator called" << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "Claptrap name: " << ClapTrap::_name << std::endl;
	std::cout << "Diamondtrap name: " << this->_name << std::endl;
}

void	DiamondTrap::attack(const std::string& target) {
	this->ScavTrap::attack(target);
}

void	DiamondTrap::printProperties() {
	std::cout << "Hit points: " << this->_hitPoints << std::endl;
	std::cout << "Energy points: " << this->_energyPoints << std::endl;
	std::cout << "Attack damage: " << this->FragTrap::_attackDamage << std::endl;
}
