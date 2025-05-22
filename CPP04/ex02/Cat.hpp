/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:15:46 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/22 18:26:34 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal {
	public:
		Cat();
		Cat(std::string type);
		Cat (const Cat& other);
		Cat& operator=(const Cat& rhs);
		~Cat();
		void	makeSound() const;
		void	setBrainIdeas(int index, const std::string& idea);
		std::string	getBrainIdeas(int index) const;
	private:
		Brain	*brain;
};

#endif
