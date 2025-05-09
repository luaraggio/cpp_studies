/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 00:16:09 by lraggio           #+#    #+#             */
/*   Updated: 2025/04/12 00:16:10 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class	Zombie
{
	private:
		std::string name;
	public:
		Zombie(std::string name);
		~Zombie(void);
		std::string getName(void) const;
		void	announce(void) const;
};

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

#endif
