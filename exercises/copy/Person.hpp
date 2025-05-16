/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Person.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 23:35:45 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/15 00:05:27 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERSON_HPP
# define PERSON_HPP

# include <iostream>

class	Person {
	private:
		std::string _name;
	public:
		//Person();
		Person(const std::string &name);
		Person& operator=(const Person &other);
		std::string	getName() const;
		void	setName(const std::string &name);
		~Person();
};

#endif
