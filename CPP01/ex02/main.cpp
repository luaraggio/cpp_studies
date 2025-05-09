/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 01:11:19 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/01 20:16:42 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*

Ref. é um ponteiro que não pode ser atribuído a um valor nulo. Essa garantia
só existe em tempo de compilação.

*/

int	main()
{
	std::string str;
	std::string *stringPTR;
	std::string &stringREF = str;

	str = "HI THIS IS BRAIN";
	stringPTR = &str;

	std::cout << &str << std::endl;
	std::cout << &stringPTR << std::endl;
	std::cout << &stringREF << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << str << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}
