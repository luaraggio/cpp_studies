/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:51:56 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/09 18:23:27 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>

class	Base {
	public:
		virtual ~Base();
};

Base*	generate(); //It randomly instantiates A, B, or C and returns the instance as a Base pointer
void	identify(Base* p);  //It prints the actual type of the object pointed to by p: "A", "B", or "C"
void	identify(Base& p); //It prints the actual type of the object referenced by p: "A", "B", or "C"

#endif
