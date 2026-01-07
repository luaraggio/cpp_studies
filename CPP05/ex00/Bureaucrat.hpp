/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:12:07 by lraggio           #+#    #+#             */
/*   Updated: 2025/12/25 16:34:09 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

/**
 * @class Bureaucrat
 * @brief Represents an employee with a hierarchical grade from 1 to 150.
 *
 * The Bureaucrat class enforces strict grade boundaries:
 * - Grade 1 is the highest rank (maximum authority).
 * - Grade 150 is the lowest rank.
 *
 * Any attempt to assign or modify the grade outside this range triggers
 * GradeTooHighException or GradeTooLowException.
 *
 * This class is central in CPP05 exercises and interacts with various Form
 * types to validate permissions based on grade thresholds.
 */

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& rhs);
		~Bureaucrat();
		std::string	getName() const;
		int	getGrade() const;
		void	incrementGrade();
		void	decrementGrade();

		class	GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
			};

			class	GradeTooLowException : public std::exception {
				public:
				const char *what() const throw();
		};
};

/**
 * @brief Stream output operator for printing a Bureaucrat.
 *
 * Format:
 *     <name>, bureaucrat grade <grade>.
 *
 * @param os Output stream.
 * @param b The Bureaucrat to print.
 * @return std::ostream& The modified stream.
 */

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
