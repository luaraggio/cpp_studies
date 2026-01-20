/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 16:58:37 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/20 13:11:45 by lraggio          ###   ########.fr       */
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

unsigned int	Span::shortestSpan() {
	if (this->_v.size() < 2) {
		throw std::runtime_error("Wrong vector size.\n");
	}
	std::sort(this->_v.begin(), this->_v.end()); //Colocar elementos do vetor em ordem crescente

	unsigned int tmp1 = this->_v[1] - this->_v[0];

	for (unsigned int i = 2; i < this->_v.size(); i++) {
		unsigned int tmp2 = this->_v[i] - this->_v[i - 1];
		if (tmp2 < tmp1) {
			tmp1 = tmp2;
		}
	}

	unsigned int shortestSpan = tmp1;
	return (shortestSpan);
}

unsigned int	Span::longestSpan() {
	if (this->_v.size() < 2) {
		throw std::runtime_error("Wrong vector size.\n");
	}

	unsigned int tmp1 = *std::max_element(_v.begin(), _v.end()); //maior
	unsigned int tmp2 = *std::min_element(_v.begin(), _v.end()); //menor

	unsigned int longestSpan = tmp1 - tmp2;
	return (longestSpan);
}
