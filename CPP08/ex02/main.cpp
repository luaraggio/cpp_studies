/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 10:00:29 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/20 20:17:52 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main() {
	std::cout << PINK "============================== BASIC SUBJECT TEST ===========================" RESET << std::endl;
	std::cout << std::endl;

	MutantStack<int> mstack;

	mstack.push(5); //[5]
	mstack.push(17); //[5] [17]

	std::cout << "Value on top: " << mstack.top() << std::endl;

	mstack.pop(); //retira quem está no topo

	std::cout << "New value on top: " << mstack.top() << std::endl;
	std::cout << "Stack size: " << mstack.size() << std::endl;

	std::cout << std::endl;

	mstack.push(3);
	mstack.push(9);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite) { //leitura na stack
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << std::endl;
	std::cout << PINK "=============================== END OF TESTS ================================" RESET << std::endl;
	return (0);
}
