/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:51:56 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/09 14:42:19 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int	j;
	int	i;

	j = 1;
	i = 0;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			std::cout << (char) std::toupper(argv[j][i]);
			i++;
		}
		j++;
	}
	std::cout << std::endl;
	return (0);
}
