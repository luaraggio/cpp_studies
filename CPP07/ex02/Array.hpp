/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:45:51 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/17 22:44:31 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstddef>
# include <stdexcept>

template <typename T>
class	Array {
	private:
		T* _ptr;
		unsigned int _length;
	public:
		Array() : _ptr(NULL), _length(0) {} //Default constructor

		Array(unsigned int n) { //Constructor with size
			this->_length = n;
			this->_ptr = new T[n]();
		}

		Array(const Array& other) { //Copy constructor
			this->_length = other._length; //Copy array length
			this->_ptr = new T[this->_length](); //Create a new T array

			for (unsigned int i = 0; i < this->_length; i++) {
				this->_ptr[i] = other._ptr[i]; //Copy elements from array
			}
		}

		Array& operator=(const Array& rhs) { //Assignment operator
			if (this != &rhs) {
				delete[] _ptr;

				this->_length = rhs._length;
				this->_ptr = new T[this->_length](); //Create a new T array

				for (unsigned int i = 0; i < this->_length; i++) {
					this->_ptr[i] = rhs._ptr[i]; //Copy elements from array
				}
			}
			return (*this);
		}

		~Array() { // Destructor
			delete[] this->_ptr;
		}

		T& operator[](unsigned int index) { // Subscript operator
			if (index >= this->_length) {
				throw std::out_of_range("Index out of bounds");
			}
			return (this->_ptr[index]);
		}

		const T& operator[](unsigned int index) const { // Const Subscript operator
			if (index >= _length) {
				throw std::out_of_range("Index out of bounds");
			}
			return (this->_ptr[index]);
		}

		unsigned int size() const {
			return (this->_length);
		}
};

#endif
