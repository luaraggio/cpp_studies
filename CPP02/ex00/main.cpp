/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 21:31:16 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/16 13:18:41 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void) {
	Fixed a;
	Fixed b( a ); //cria o objeto b como uma cópia de a -> a cópia acontece no momento da construção de b -> b é construído como a desde o momento zero
	Fixed c; //cria c
	c = b; //atribui b a c -> operador de atribuição -> a cópia acontece depois da construção de c -> c é sobrescrito com os dados de b
	//std::cout << "A" << std::endl;
	std::cout << a.getRawBits() << std::endl;
	//std::cout << "B" << std::endl;
	std::cout << b.getRawBits() << std::endl;
	//std::cout << "C" << std::endl;
	std::cout << c.getRawBits() << std::endl;
	//Primeiro destrói c, depois b, depois a (ordem inversa da criação -> stack.
	return 0;
}
