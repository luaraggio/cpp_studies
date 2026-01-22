/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 08:34:42 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/22 19:08:16 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# define RESET	"\033[0m"
# define PINK	"\033[0;35m"
# define RED 	"\033[0;31m"
# define BLUE "\033[1;34m"

# include <iostream>
# include <stdexcept>
# include <vector>
# include <iterator>
#include <algorithm>

class Span {
	private:
		unsigned int _n;
		std::vector<int> _v;
	public:
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& rhs);
		~Span();

		void	addNumber(unsigned int n);
		unsigned int	shortestSpan(); //unsigned int porque é uma distância!!!
		unsigned int	longestSpan();

		//Adiciona múltiplos números usando um range de iterador, pra que n precise rodar addNumber x vezes
		template <typename Iterator> //aceita qualquer tipo de iterador
			void		addNumber(Iterator begin, Iterator end) { //begin: início, end: um após o último
				unsigned int countElements = std::distance(begin, end);
				if (this->_v.size() + countElements > this->_n) { //Garante que n vai ultrapassar o limite máximo definido no construtor
					throw std::runtime_error( RED "Span is full" RESET);
				}
				this->_v.insert(this->_v.end(), begin, end); //dá push back item por item, de begin a end
			}
};

#endif
