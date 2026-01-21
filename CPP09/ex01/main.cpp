/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:18:10 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/21 15:43:26 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Error: Wrong arguments. It must be: ./RPN <numbers> <operations>." << std::endl;
		return (-1);
	}
	try {
		RPN rpn;
		rpn.performRPN(argv[1]);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
