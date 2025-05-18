/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 20:06:52 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/17 16:31:35 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap clap_trap("Ajuda humanitaria");

	clap_trap.takeDamage(3);
	clap_trap.beRepaired(2);
	clap_trap.takeDamage(20);
	clap_trap.beRepaired(5);
}
