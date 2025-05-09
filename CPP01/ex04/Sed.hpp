/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:34:55 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/06 19:37:55 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
 #define SED_HPP

 #include <iostream>
 #include <fstream>

enum	e_error {
	NO_ERROR,
	ERROR
};

class	Sed {
	public:
		void	sedFile();
};


#endif
