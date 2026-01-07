/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:04:13 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/06 17:16:47 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
	if (this != &rhs) {
		this->_target = rhs._target;
	}
	return (*this);
}

void RobotomyRequestForm::executeAction() const {
	std::cout << "* drilling noises *" << std::endl;

	if (std::rand() % 2) {
		std::cout << _target << " has been robotomized successfully" << std::endl;
	}
	else {
		std::cout << "Robotomy failed on " << _target << std::endl;
	}
}
