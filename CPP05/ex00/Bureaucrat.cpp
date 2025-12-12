/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:48:32 by lraggio           #+#    #+#             */
/*   Updated: 2025/11/24 15:17:48 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/**
 * @brief Main constructor for the Bureaucrat class.
 *
 * Initializes the bureaucrat with a given name and grade.
 * In the 42 grade system:
 * - Grade 1 is the HIGHEST possible rank.
 * - Grade 150 is the LOWEST possible rank.
 *
 * This constructor enforces the valid grade range upon creation.
 *
 * @param name The bureaucrat's immutable name.
 * @param grade The bureaucrat's initial grade.
 *
 * @throws GradeTooHighException If grade < 1.
 * @throws GradeTooLowException If grade > 150.
 */

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
	if (grade < 1) {
		throw GradeTooHighException();
	}
	if (grade > 150) {
		throw GradeTooLowException();
	}
	this->_grade = grade;
}

/**
 * @brief Default destructor.
 *
 * No dynamic allocation is used, so nothing special is required.
 */

Bureaucrat::~Bureaucrat() {}

/**
 * @brief Copy constructor.
 *
 * Creates a new Bureaucrat from another instance.
 * The name attribute is const and therefore copied directly.
 *
 * @param other The Bureaucrat to copy.
 */

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade) {}

/**
 * @brief Copy assignment operator.
 *
 * Since the name attribute is const, only the grade can be reassigned.
 *
 * @param rhs The right-hand side Bureaucrat to assign from.
 * @return Reference to the current instance.
 */

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
	if (this != &rhs) {
		this->_grade = rhs._grade;
	}
	return (*this);
}

/**
 * @brief Returns the bureaucrat's name.
 *
 * @return std::string The name of the Bureaucrat.
 */

std::string	Bureaucrat::getName() const {
	return (this->_name);
}

/**
 * @brief Returns the bureaucrat's current grade.
 *
 * @return int The grade value.
 */

int	Bureaucrat::getGrade() const {
	return (this->_grade);
}

/**
 * @brief Decreases the bureaucrat's rank (numerically increases the grade).
 *
 * This lowers the bureaucrat’s authority.
 * The grade cannot exceed 150.
 *
 * @throws GradeTooLowException If the grade is already >= 150.
 */

void	Bureaucrat::decrementGrade() {
	if (this->_grade >= 150) {
		throw GradeTooLowException();
	}
	this->_grade++;
}

/**
 * @brief Increases the bureaucrat's rank (numerically decreases the grade).
 *
 * This raises the bureaucrat’s authority.
 * The grade cannot be lower than 1.
 *
 * @throws GradeTooHighException If the grade is already <= 1.
 */

void	Bureaucrat::incrementGrade() {
	if (this->_grade <= 1) {
		throw GradeTooHighException();
	}
	this->_grade--;
}

/**
 * @brief Error message for a grade that is too high (grade < 1).
 *
 * @return const char* Human-readable error message.
 */

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

/**
 * @brief Error message for a grade that is too low (grade > 150).
 *
 * @return const char* Human-readable error message.
 */

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

/**
 * @brief Overload of the insertion operator for easy printing.
 *
 * Output format:
 *    <name>, bureaucrat grade <grade>.
 *
 * @param os Output stream.
 * @param b The Bureaucrat to print.
 * @return std::ostream& The updated output stream.
 */

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (os);
}
