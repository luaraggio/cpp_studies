/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HarlFilter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 19:20:04 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/13 10:17:00 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HarlFilter.hpp"

HarlFilter::HarlFilter() {
	this->log_methods[0] = &HarlFilter::debug;
	this->log_methods[1] = &HarlFilter::info;
	this->log_methods[2] = &HarlFilter::warning;
	this->log_methods[3] = &HarlFilter::error;
	this->message_list[0] = "DEBUG";
	this->message_list[1] = "INFO";
	this->message_list[2] = "WARNING";
	this->message_list[3] = "ERROR";
}

HarlFilter::~HarlFilter() {}

void	HarlFilter::debug(void) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-"
	"ketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}

void	HarlFilter::info(void) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put"
	"enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	std::cout << std::endl;
}

void	HarlFilter::warning(void) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for"
	"years, whereas you started working here just last month." << std::endl;
	std::cout << std::endl;
}

void	HarlFilter::error(void) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

void	HarlFilter::complain(std::string level)
{
	int	first_method = -1;

	for (size_t i = 0; i < level.length(); i++) {
		level[i] = toupper(level[i]);
	}
	for (int i = 0; i < 4; i++) {
		if (level == message_list[i]) {
			first_method = i;
			break ;
		}
	}
	switch (first_method) {
		case 0:
			CALL_MEMBER_FN(*this, this->log_methods[0])();
		case 1:
			CALL_MEMBER_FN(*this, this->log_methods[1])();
		case 2:
			CALL_MEMBER_FN(*this, this->log_methods[2])();
		case 3:
			CALL_MEMBER_FN(*this, this->log_methods[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
