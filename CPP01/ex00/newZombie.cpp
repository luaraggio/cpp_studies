/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 22:17:17 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/01 18:02:32 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
 * @brief	Zombie* Zombie::newZombie
 *			returns a pointer to zombie
 *
 *	@param std::string name
 *
 *	@resume create a zombie in heap (with the world new), name the zombie
 *		returns the zombie pointer
 *
 *		//create a zombie
 *		//name a zombie
 *		//return the zombie pointer
 *
 *	@return the zombie pointer
 */

/*
	Por que o ponteiro precisa apontar pra um zumbi que ainda existe após o fim da função?
	Porque você quer usar o zumbi depois que a função acabar.

	Zombie* newZombie(std::string name)
	{
		Zombie z(name); // stack
		return (&z);      // retorna ponteiro pra variável local
	}
	// ao sair da função, z é destruído automaticamente!
	// O ponteiro retornado aponta para memória inválida.
	// Usar esse ponteiro vai dar comportamento indefinido: pode parecer funcionar,
		mas é bug.

*/

Zombie	*newZombie(std::string name)
{
	Zombie	*z;

	z = new Zombie(name);
	z->announce();
	return (z);
}
