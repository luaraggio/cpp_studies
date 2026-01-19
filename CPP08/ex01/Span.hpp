/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 08:34:42 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/18 19:22:49 by lraggio          ###   ########.fr       */
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
		Span	shortestSpan();
		Span	longestSpan();
};

#endif
