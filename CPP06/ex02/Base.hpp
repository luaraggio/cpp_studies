/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:51:56 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/09 16:29:13 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>

class	Base {
	public:
		virtual ~Base();

		Base*	generate();
		void	identify(Base* p);
		void	identify(Base& p);
};

#endif
