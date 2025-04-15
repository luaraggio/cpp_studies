/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:19:51 by lraggio           #+#    #+#             */
/*   Updated: 2025/04/09 16:31:55 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {};

Contact::~Contact() {};

void	Contact::printDetailedContact(Contact contact) const
{
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name is: " << lastName << std::endl;
	std::cout << "Nickname is: " << nickname << std::endl;
	std::cout << "Phone number is: " << phoneNumber << std::endl;
	std::cout << "Darkest secret: " << darkestSecret << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
}

void	Contact::printContacts(Contact contact, std::string index) const
{
	std::cout << "| Index | First Name | Last Name | Nickname |\n";
	std::cout << std::setw(11) << format_string_table(contact.firstName) << " |";
	std::cout << std::setw(10) << format_string_table(contact.lastName) << " |";
	std::cout << std::setw(9) << format_string_table(contact.nickname) << " |" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
}

void	Contact::setContact()
{
	setFirstName();
	setLastName();
	setNickname();
	setPhoneNumber();
	setDarkestSecret();
	std::cout << "The contact was successfully added! ✅" << std::endl;
}

void	Contact::setFirstName()
{
	std::string input;

	std::cout << "First Name: ";
	std::getline(std::cin, input);
	while (!is_valid_input(input, "'First Name'"))
	{
		std::cout << "Enter a valid first name: ";
		std::getline(std::cin, input);
	}
	this->firstName = format_string(input);
}

void	Contact::setLastName()
{
	std::string input;

	std::cout << "Last Name: ";
	std::getline(std::cin, input);
	while (!is_valid_input(input, "'Last Name'"))
	{
		std::cout << "Enter a valid last name: ";
		std::getline(std::cin, input);
	}
	this->lastName = format_string(input);
}

void	Contact::setNickname()
{
	std::string input;

	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	while (!is_valid_input(input, "'Nickname'"))
	{
		std::cout << "Enter a valid nickname: ";
		std::getline(std::cin, input);
	}
	this->nickname = input;
}

void	Contact::setPhoneNumber()
{
	std::string input;

	std::cout << "PhoneNumber: ";
	std::getline(std::cin, input);
	while (!is_valid_input(input, "'Phone Number'"))
		{
			std::cout << "Enter a valid phone number: ";
			std::getline(std::cin, input);
		}
	this->phoneNumber = input;
}

void	Contact::setDarkestSecret()
{
	std::string input;

	std::cout << "Tell me your darkest secret. I sware I'll keep this a secret." << std::endl;
	std::getline(std::cin, input);
	while (!is_valid_input(input, "'Darkest Secret'"))
		{
			std::cout << "It's okay if you don't want to share a secret with me. ";
			std::cout << "You can also write something randomly 😝 " << std::endl;
			std::getline(std::cin, input);
		}
	this->darkestSecret = input;
}

std::string	Contact::getFirstName() const
{
	return (this->firstName);
}

std::string	Contact::getLastName() const
{
	return (this->lastName);
}

std::string	Contact::getNickname() const
{
	return (this->nickname);
}

std::string	Contact::getPhoneNumber() const
{
	return (this->phoneNumber);
}

std::string	Contact::getDarkestSecret() const
{
	return (this->darkestSecret);
}