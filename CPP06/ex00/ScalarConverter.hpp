/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:51:43 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/08 17:42:45 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class	ScalarConverter {
	private:
		ScalarConverter();
		~ScalarConverter();
	public:
		static void	converter(const std::string input);
};

class HandleScalarTypes {
	private:
		HandleScalarTypes();
		~HandleScalarTypes();
	public:
		static void	handleChar(const std::string& input);
		static void	handleInt(const std::string& input);
		static void	handleFloat(const std::string& input);
		static void	handleDouble(const std::string& input);
};

#endif
