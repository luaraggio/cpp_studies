/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:57:27 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/12 17:34:55 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T>
void swap(T& a, T& b) {
	T c;

	c = a;
	a = b;
	b = c;
}

template <typename T>
T min(T a, T b) {
	return(a < b ? a : b);
}

template <typename T>
T max(T a, T b) {
	return(a > b ? a : b);
}

#endif
