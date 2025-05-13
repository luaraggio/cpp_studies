/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 19:20:04 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/13 09:45:57 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
	this->log_methods[0] = &Harl::error;
	this->log_methods[1] = &Harl::warning;
	this->log_methods[2] = &Harl::info;
	this->log_methods[3] = &Harl::debug;
	this->message_list[0] = "ERROR";
	this->message_list[1] = "WARNING";
	this->message_list[2] = "INFO";
	this->message_list[3] = "DEBUG";
}

Harl::~Harl() {}

void	Harl::debug(void)
{
	std::cout << "DEBUG LEVEL" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-"
	"ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "INFO LEVEL" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put"
	"enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "WARNING LEVEL" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for"
	"years, whereas you started working here just last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "ERROR LEVEL" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	int	first_method = -1;

	for (int i = 0; i < 4; i++) {
		if (level == message_list[i]) {
			first_method = i;
			break ;
		}
	}
	CALL_MEMBER_FN(*this, this->log_methods[first_method]) ();
}
