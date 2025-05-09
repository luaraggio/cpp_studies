/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 00:00:56 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/05 19:31:28 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef define HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon Weapon;
	public:
		HumanA();
		~HumanA();
		void	attack();
};


#endif

