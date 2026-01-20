/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 08:34:42 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/20 19:57:26 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# define RESET	"\033[0m"
# define PINK	"\033[0;35m"
# define RED 	"\033[0;31m"
# define BLUE "\033[1;34m"

# include <iostream>

// ** Como stack de fato é:
// template <class T, class Container = std::deque<T> >
// class stack {
// public:
// 	typedef Container container_type;

// protected:
// 	container_type c;

// public:
// 	explicit stack(const container_type& cont = container_type())
// 		: c(cont) {}

// 	void push(const T& value) { c.push_back(value); }
// 	void pop() { c.pop_back(); }
// 	T& top() { return c.back(); }
// 	bool empty() const { return c.empty(); }
// 	size_t size() const { return c.size(); }
// };

template <typename T, class C = std::deque<T> >
class MutantStack : public std::stack<T, C> {
	public:
		MutantStack() : std::stack<T>() {}

		MutantStack(const MutantStack& other) : std::stack<T>(other) {}

		MutantStack& operator=(const MutantStack& rhs) {
			if (this != &rhs) {
				std::stack<T>::operator=(rhs);
			}
			return (*this);
		}

		~MutantStack() {}
		typedef typename C::iterator iterator;

		// typedef typename std::stack<T>::container_type::iterator it;
		iterator	begin() {
			return (this->c.begin());
		}

		iterator	end() {
			return (this->c.end());
		}
};

#endif
