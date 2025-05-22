/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 22:26:34 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/22 17:54:54 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {
	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& rhs);
		~Brain();
		void	setIdeas(int index, const std::string& ideas);
		std::string	getIdeas(int index) const;
	private:
		std::string ideas[100];
};

#endif
