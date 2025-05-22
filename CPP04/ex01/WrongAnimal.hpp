/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:03:45 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/18 22:15:31 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal operator=(const WrongAnimal& rhs);
		virtual ~WrongAnimal();
		std::string getType() const;
		virtual void	makeSound() const;
	protected:
		std::string _type;
};

#endif
