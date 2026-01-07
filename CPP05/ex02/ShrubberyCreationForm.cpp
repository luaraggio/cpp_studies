/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 11:55:30 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/07 19:02:16 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"
# include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 135, 147), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
	if (this != &rhs) {
		this->_target = rhs._target;
	}
	return (*this);
}

void ShrubberyCreationForm::executeAction() const {
	std::ofstream file((this->_target + "_shrubbery").c_str());
	if (!file) {
		std::cout << "ShrubberyCreationForm: No file." << std::endl;
		return ;
	}

	file << "            &&& &&  & &&\n";
	file << "      && &\\/&\\|& ()|/ @, &&\n";
	file << "      &\\/( /&/&||/& /_/)_&/_&\n";
	file << "   &() &\\/&|()|/&\\/ '%\" & ()\n";
	file << "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n";
	file << "&&   && & &| &| /& & % ()& /&&\n";
	file << " ()&_---()&\\&\\|&&-&&--%---()~\n";
	file << "     &&     \\|||\n";
	file << "             |||\n";
	file << "             |||\n";
	file << "             |||\n";
	file << "       , -=-~  .-^- _\n";
	file.close();
}
