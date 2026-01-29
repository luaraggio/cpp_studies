/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:18:47 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/28 21:19:29 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

class	RPN {
	private:
		std::stack<int> _stack;
		bool isNumberToken(const std::string& token);
		bool isOperatorToken(const std::string& token);

	public:
		RPN();
		~RPN();
		RPN (const RPN& other);
		RPN& operator=(const RPN& other);

		int performOperations(int op1, int op2, const std::string& op);
		void performRPN(const std::string& input);
};

#endif
