/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:59:19 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/09 14:46:53 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error: invalid input. It must be: ./convert <literal>" << std::endl;
		return (1);
	}

	ScalarConverter::converter(argv[1]);
	return (0);
}
