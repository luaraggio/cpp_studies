/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 08:34:42 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/18 13:44:22 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# define RESET	"\033[0m"
# define PINK	"\033[0;35m"
# define RED 	"\033[0;31m"
# define BLUE "\033[1;34m"

# include <iostream>
# include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int integer) {
	typename T::iterator it;

	for (it = container.begin(); it != container.end(); ++it) {
		if (*it == integer) {
			return (it);
		}
	}
	throw std::out_of_range(RED "No occurence of the second parameter in the first parameter." RESET);
};

#endif
