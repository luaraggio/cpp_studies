/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 11:09:21 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/06 17:33:27 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute):
_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {}

AForm::~AForm() {}

AForm::AForm(const AForm& other): _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign),
 _gradeToExecute(other._gradeToExecute) {}

std::string	AForm::getName() const {
	return (this->_name);
}

bool	AForm::getIsSignedOrNot() const {
	return (this->_isSigned);
}

int	AForm::getGradeToSign() const {
	return (this->_gradeToSign);
}

int	AForm::getGradeToExecute() const {
	return (this->_gradeToExecute);
}

AForm& AForm::operator=(const AForm& rhs) {
	if (this != &rhs) {
		this->_isSigned = rhs._isSigned;
	}
	return (*this);
}

void	AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() >= this->_gradeToSign) {
		throw GradeTooLowException();
	}
	this->_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Grade is too low!");
}

std::ostream& operator<<(std::ostream& os, const AForm& b) {
	os << "AForm " << b.getName()
	<< ", signed: " << (b.getIsSignedOrNot() ? "'Yes'" : "'No'")
	<< ", grade to sign: " << b.getGradeToSign()
	<< ", grade to execute: " << b.getGradeToExecute();
	return (os);
}

const char *AForm::FormNotSignedException::what() const throw() {
	return "form is not signed";
}

void AForm::execute(Bureaucrat const & executor) const {
	if (!this->_isSigned) {
		throw FormNotSignedException();
	}

	if (executor.getGrade() > this->_gradeToExecute) {
		throw GradeTooLowException();
	}
	this->executeAction();
}
