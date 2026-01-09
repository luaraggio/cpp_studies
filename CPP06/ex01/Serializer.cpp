/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:51:47 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/09 15:28:37 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

uintptr_t	Serializer::serialize(Data* ptr) {
	uintptr_t	prt_t; // unsigned integer type uintptr_t

	prt_t = reinterpret_cast<uintptr_t>(ptr);
	return (prt_t);
}

Data*	Serializer::deserialize(uintptr_t raw) {
	Data*	ptr;

	ptr = reinterpret_cast<Data*>(raw);
	return (ptr);
}
