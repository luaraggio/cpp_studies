/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 22:13:07 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/18 22:14:37 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		WrongCat(std::string type);
		WrongCat (const WrongCat& other);
		WrongCat& operator=(const WrongCat& rhs);
		~WrongCat();
		void	makeSound() const;
};

#endif
