/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:57:26 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/13 15:29:17 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

#define RESET	"\033[0m"
#define PINK	"\033[0;35m"
#define RED 	"\033[0;31m"

void	testFunction(int &x) {
	std::cout << "Hi from testFunction(" << x << ")" << std::endl;
}

void testIncrement(int &x) {
	x += 1;
	std::cout << "Hi from testIncrement(" << x << ")" << std::endl;
}

int	main() {
	std::cout << PINK "========== TESTS ==========" RESET << std::endl;
	int	array[5] = {1, 2, 3, 4, 5};
	int	array2[3] = {1, 2, 3};

	::iter(array, 5, testFunction);
	std::cout << std::endl;
	::iter(array2, 3, testIncrement);

	std::cout << PINK "========== END OF TESTS ==========" RESET << std::endl;
	return (0);
}
