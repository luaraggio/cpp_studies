/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 16:58:37 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/19 19:16:02 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span& other) : _n(other._n), _v(other._v) {}

Span& Span::operator=(const Span& rhs) {
	if (this != &rhs) {
		this->_n = rhs._n;
		this->_v = rhs._v;
	}
	return (*this);
}

Span::~Span() {}

void	Span::addNumber(unsigned int n) {
	if (this->_v.size() >= n) {
		throw std::runtime_error("There are already N elements stored");
		return ;
	}
	this->_v.push_back(n);
}

Span	Span::shortestSpan() {}

Span	Span::longestSpan() {}
