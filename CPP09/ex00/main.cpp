/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:20:56 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/28 22:03:18 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <limits>

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return (-1);
	}
	try {
		BitcoinExchange btc;

		btc.parseDatabase("data.csv");
		btc.parseInputFile(argv[1]);

	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
