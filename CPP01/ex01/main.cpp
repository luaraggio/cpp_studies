/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 00:19:28 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/01 18:40:53 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie* foo;
	int	N;

	N = 4;
	foo = zombieHorde(N, "Foo");
	for (int i = 0; i < N; i++) {
		foo[i].announce();
	}
	delete[] foo;
}
