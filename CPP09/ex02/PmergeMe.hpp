/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:18:47 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/21 16:50:46 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_HPP
# define PMERGE_HPP

# include <iostream>
# include <deque>
# include <vector>

class	PmergeMe {
	private:
		std::vector<int> _v;
		std::deque<int>  _d;

		void	parseInput(char **argv);

		void fordJohnsonVector(std::vector<int>& v); //vector
		void insertPendingsVector(std::vector<int>& main, std::vector<int>& pend);

		void fordJohnsonDeque(std::deque<int>& d); //deque
		void insertPendingsDeque(std::deque<int>& main, std::deque<int>& pend);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void performPmergeMe(char **argv);
};

#endif
