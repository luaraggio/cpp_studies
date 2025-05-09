/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:27:38 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/06 20:02:43 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

void	parse_input(char **argv)
{
	std::string filename;
	std::string s1;
	std::string s2;

	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];

	if (!s1)

	if (!s2)
		
	std::fstream();
	/*
		arquivo pode não existir
		arquivo pode não ser aberto
		arquivo pode estar vazio
	*/
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error.\nInvalid arguments. It must be: ./sed <file.txt> <s1> <s2>" << std::endl;
		return (ERROR);
	}
	parse_input(argv);
}
