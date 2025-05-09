/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:55:25 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/05 19:36:48 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon(){}

void	Weapon::setType(std::string type)
{
	this->type = type;
}

const std::string& 	Weapon::getType() const
{
	return (this->type);
}
