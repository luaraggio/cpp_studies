/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:07:20 by lraggio           #+#    #+#             */
/*   Updated: 2025/11/24 15:30:50 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute):
_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSignedOrNot(false) {}

Form::~Form() {}

Form::Form(const Form& other): _name(other._name), _gradeToSign(other._gradeToSign),
 _gradeToExecute(other._gradeToExecute), _isSignedOrNot(other._isSignedOrNot) {}

 std::string	Form::getName() const {

 }
