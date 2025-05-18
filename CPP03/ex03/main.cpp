/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:43:08 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/18 18:49:01 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main() {
	DiamondTrap a("Luara");
	a.whoAmI();
	a.attack("Enemy");
	a.printProperties();
	a.attack("Enemy");
}
