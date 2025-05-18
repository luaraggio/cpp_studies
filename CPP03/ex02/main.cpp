/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 20:06:52 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/17 21:27:25 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
	FragTrap a("Robot");
	//FragTrap b(a);
	FragTrap c("Juliana");
	c = a;

	a.attack("Enemy");
	a.takeDamage(20);
	a.beRepaired(10);
	a.highFivesGuys();
	/*std::cout << "------------------------------------------------------" << std::endl;
	b.attack("Enemy");
	b.takeDamage(20);
	b.beRepaired(10);
	b.highFivesGuys();*/
	std::cout << "------------------------------------------------------" << std::endl;
	c.attack("Enemy");
	c.takeDamage(20);
	c.beRepaired(10);
	c.highFivesGuys();
}

