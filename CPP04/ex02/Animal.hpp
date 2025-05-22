/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:14:13 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/22 20:34:38 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal& other);
		Animal operator=(const Animal& rhs);
		virtual ~Animal();
		std::string getType() const;
		virtual void	makeSound() const = 0;
	protected:
		std::string _type;
};

#endif
