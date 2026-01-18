/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:57:27 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/13 14:51:58 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <cstddef>

template <typename T>
void	iter(T* array, const size_t lenght, void (*f)(T&)) {
	for (size_t i = 0; i < lenght; i++) {
		f(array[i]);
	}
}

#endif
