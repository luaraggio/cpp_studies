/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:54:28 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/01 20:15:04 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef define WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
	private:
		std::string	type;
	public:
		Weapon(std::string type);
		~Weapon(void);
		const std::string &getType() const;
		void	setType(std::string type);
};


#endif
