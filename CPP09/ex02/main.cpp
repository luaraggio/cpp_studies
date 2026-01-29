/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:18:10 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/29 15:14:51 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Error: arguments. It must be ./PmergeMe <sequence>." << std::endl;
		return (-1);
	}

	try {
		PmergeMe pmerge;
		pmerge.performPmergeMe(argv);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
