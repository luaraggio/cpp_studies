/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:34:44 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/28 21:21:35 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <climits>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		this->_v = other._v;
		this->_d = other._d;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseInput(char **argv) {
	for (int i = 1; argv[i]; i++) {
		std::string s(argv[i]);

		if (s.empty()) {
			throw std::runtime_error("Error: empty input.");
		}

		for (size_t j = 0; j < s.size(); j++) {
			if (!isdigit(s[j])) {
				throw std::runtime_error("Error: non-numeric character found.");
			}
		}

		long n = std::strtol(s.c_str(), NULL, 10);
		if (n <= 0) {
			throw std::runtime_error("Error: number must be a positive integer.");
		}

		if (n > INT_MAX) {
			throw std::runtime_error("Error: number out of range.");
		}

		this->_v.push_back(n);
		this->_d.push_back(n);
	}
}

void PmergeMe::insertPendingsVector(std::vector<int>& main, std::vector<int>& pend) { //insere os menores
	//Implementação da inserção dos elementos pendentes no vector
	for (size_t i = 0; i < pend.size(); i++) {
		int value = pend[i];

		size_t left = 0;
		size_t right = main.size();

		while (left < right) {
			size_t mid = (left + right) / 2;

			if (value < main[mid])
				right = mid;
			else
				left = mid + 1;
		}

		main.insert(main.begin() + left, value);
	}
}

void	PmergeMe::fordJohnsonVector(std::vector<int>& v) { //ordena os maiores
	//Implementação do algoritmo ford-johnson para vector
	// Quebrar em pares, ordenar cada par e separar em main e pend

	if (v.size() <= 1) {
		return ;
	}

	std::vector<int> main;
	std::vector<int> pend;

	for (size_t i = 0; i + 1 < v.size(); i +=2) {
		if (v[i] < v[i + 1]) {
			main.push_back(v[i + 1]); //maior
			pend.push_back(v[i]); // menor
		} else {
			main.push_back(v[i]); //maior
			pend.push_back(v[i + 1]); //menor
		}
	}
	if (v.size() % 2 != 0) { //se sobrar algum elemento (tamanho ímpar!!)
		pend.push_back(v.back()); //Pode dar erro aqui!!!
	}

	fordJohnsonVector(main);
	insertPendingsVector(main, pend);
	v = main;
}

void	PmergeMe::fordJohnsonDeque(std::deque<int>& d) {
	//Implementação do algoritmo ford-johnson para deque
	if (d.size() <= 1) {
		return ;
	}

	std::deque<int> main;
	std::deque<int> pend;

	for (size_t i = 0; i + 1 < d.size(); i +=2) {
		if (d[i] < d[i + 1]) {
			main.push_back(d[i + 1]); //maior
			pend.push_back(d[i]); // menor
		} else {
			main.push_back(d[i]); //maior
			pend.push_back(d[i + 1]); //menor
		}
	}
	if (d.size() % 2 != 0) { //se sobrar algum elemento (tamanho ímpar!!)
		pend.push_back(d.back());
	}

	fordJohnsonDeque(main);
	insertPendingsDeque(main, pend);
	d = main;
}

void PmergeMe::insertPendingsDeque(std::deque<int>& main, std::deque<int>& pend) {
	//Implementação da inserção dos elementos pendentes no deque
	for (size_t i = 0; i < pend.size(); i++) {
		int value = pend[i];

		size_t left = 0;
		size_t right = main.size();

		while (left < right) {
			size_t mid = (left + right) / 2;

			if (value < main[mid])
				right = mid;
			else
				left = mid + 1;
		}
		main.insert(main.begin() + left, value);
	}
}

void PmergeMe::performPmergeMe(char **argv) {

	parseInput(argv); //trata input para receber apenas números inteiros e positivos e preenche _v e _q

	std::cout << "Before: ";
	for (size_t i = 0; i < _v.size(); i++) {
		std::cout << _v[i] << " ";
	}
	std::cout << std::endl;

	//mede tempo do vector
	clock_t startVec = clock();
	fordJohnsonVector(this->_v);
	clock_t endVec = clock();

	double timeVec = static_cast<double>(endVec - startVec)
		/ CLOCKS_PER_SEC * 1e6;

	//mede tempo do deque
	clock_t startDeq = clock();
	fordJohnsonDeque(this->_d);
	clock_t endDeq = clock();

	double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1e6;

	std::cout << "After:  ";
	for (size_t i = 0; i < this->_v.size(); i++) {
		std::cout << this->_v[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << this->_v.size() << " elements with std::vector : " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << this->_d.size() << " elements with std::deque : " << timeDeq << " us" << std::endl;
}
