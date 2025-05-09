/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 22:11:51 by lraggio           #+#    #+#             */
/*   Updated: 2025/04/11 23:37:22 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
};

Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " was destroyed!" << std::endl;
};

void	Zombie::announce() const
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string	Zombie::getName() const
{
	return (this->name);
}
