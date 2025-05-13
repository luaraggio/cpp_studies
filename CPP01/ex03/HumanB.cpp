/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 00:02:56 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/10 16:03:15 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->name = name;
	this->weapon = NULL;
}

HumanB::~HumanB(){}

void	HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}

void	HumanB::attack()
{
	if (this->weapon == NULL) {
		std::cout << this->name << " is defenseless, they have no weapon " << std::endl;
		return ;
	}
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

