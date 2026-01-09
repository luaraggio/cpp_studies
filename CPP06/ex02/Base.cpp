/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:51:47 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/09 16:33:44 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base() {}

// Base * generate(void);

// void identify(Base* p);

// void identify(Base& p);

void	createRandomClass() {
	
}

Base*	Base::generate() {
	// It randomly instantiates A, B, or C and returns the instance as a Base pointer. Feel free
	// to use anything you like for the random choice implementation

	createRandomClass();
}

void	Base::identify(Base* p) {
	// It prints the actual type of the object pointed to by p: "A", "B", or "C"
}

void	Base::identify(Base& p) {
	// It prints the actual type of the object referenced by p: "A", "B", or "C". Using a pointer
	// inside this function is forbidden
}
