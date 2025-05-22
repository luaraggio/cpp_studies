/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:15:45 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/22 18:15:44 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal {
	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& rhs);
		~Dog();
		void	makeSound() const;
		void setBrainIdeas(int index, const std::string& idea);
		std::string getBrainIdeas(int index) const;
	private:
		Brain *brain;
};

#endif
