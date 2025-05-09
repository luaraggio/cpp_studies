/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 00:03:39 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/01 19:26:38 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef define HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon Weapon;
	public:
	HumanB(/* args */);
	~HumanB();
};

void	attack();

#endif
