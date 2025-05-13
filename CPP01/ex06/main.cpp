/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 19:19:45 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/13 10:17:08 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HarlFilter.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error. Pass a valid input to Harl Filter." << std::endl;
		return (1);
	}
	HarlFilter harlFilter;

	harlFilter.complain(argv[1]);
}
