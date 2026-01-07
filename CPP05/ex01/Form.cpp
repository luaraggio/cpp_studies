/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:07:20 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/06 15:10:23 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string name, int gradeToSign, const int gradeToExecute):
_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {}

Form::~Form() {}

Form::Form(const Form& other): _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign),
 _gradeToExecute(other._gradeToExecute) {}

std::string	Form::getName() const {
	return (this->_name);
}

bool	Form::getIsSignedOrNot() const {
	return (this->_isSigned);
}

int	Form::getGradeToSign() const {
	return (this->_gradeToSign);
}

int	Form::getGradeToExecute() const {
	return (this->_gradeToExecute);
}

Form& Form::operator=(const Form& rhs) {
	if (this != &rhs) {
		this->_isSigned = rhs._isSigned;
	}
	return (*this);
}

// 	It changes the form’s status to signed if the bureaucrat’s grade is high enough
// (greater than or equal to the required one).

void	Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() >= this->_gradeToSign) {
		throw GradeTooLowException();
	}
	this->_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Grade is too low!");
}

std::ostream& operator<<(std::ostream& os, const Form& b) {
	os << "Form " << b.getName()
	<< ", signed: " << (b.getIsSignedOrNot() ? "Yes" : "No")
	<< ", grade to sign: " << b.getGradeToSign()
	<< ", grade to execute: " << b.getGradeToExecute();
	return (os);
}
