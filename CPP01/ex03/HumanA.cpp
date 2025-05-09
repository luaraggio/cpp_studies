/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 00:03:46 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/05 19:45:59 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(){}

HumanA::~HumanA(){}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with their" << this->Weapon << std::endl;
}
