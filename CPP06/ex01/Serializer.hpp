/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:51:56 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/09 15:47:12 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <cstdint>
# include <iostream>

struct Data {
		std::string name;
		int	value;
};

class	Serializer {
	private:
		Serializer();
		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr);// It takes a pointer and converts it to the unsigned integer type uintptr_t
		static Data* deserialize(uintptr_t raw);//It takes an unsigned integer parameter and converts it to a pointer to Data
};

#endif
