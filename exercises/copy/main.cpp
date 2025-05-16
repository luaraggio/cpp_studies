/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 23:28:12 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/14 23:53:14 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Person.hpp"

int	main(void)
{
	Person pessoaA("Luara");
	Person pessoaB("Gabriel");

	std::cout << " Pessoa A: " << pessoaA.getName() << std::endl;
	std::cout << " Pessoa B: " << pessoaB.getName() << std::endl;
}
