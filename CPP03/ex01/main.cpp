/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 20:06:52 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/18 14:40:19 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
	ScavTrap serena("Serena");

	serena.attack("Enemy");
	serena.takeDamage(30);
	serena.beRepaired(20);
	serena.guardGate();
	return (0);
}

