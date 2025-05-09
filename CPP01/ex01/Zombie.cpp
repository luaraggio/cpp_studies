/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 00:18:57 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/01 18:26:08 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){};

Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " was destroyed!" << std::endl;
};

void	Zombie::announce() const
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}

std::string	Zombie::getName() const
{
	return (this->name);
}

