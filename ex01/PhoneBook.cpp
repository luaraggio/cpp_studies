/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:51:46 by lraggio           #+#    #+#             */
/*   Updated: 2025/04/09 16:31:33 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::~PhoneBook() {};

PhoneBook::PhoneBook()
{
	this->numberOfContacts = 0;
	this->index = 0;
};

void PhoneBook::addContact(Contact contact)
{
	int	position;

	position = this->index % 8;
	this->contacts[position] = contact;
	this->index++;
	contact.setContact();
}

void    print_phonebook()
{
    std::cout << "\n📖 Phonebook Contacts:\n";
	std::cout << "--------------------------------------------\n";
	std::cout << "| Index | First Name | Last Name | Nickname |\n";
	std::cout << "--------------------------------------------\n";
}

void PhoneBook::displayAllContacts(Contact contact, std::string	command) const
{
    int i;

    i = 0;
    print_phonebook();
    while(i < 8)
    {
		this->contacts[this->index].printContacts(contact, command);
        i++;
    }
	displayDetailedContact(contact);
}

void PhoneBook::displayDetailedContact(Contact contact) const
{
	std::string index;

	while(42)
	{
		std::cout << "Insira a joça do index:";
		std::getline(std::cin, index);
		if (!(index >= "1" && index <= "9"))
		{
			std::cout << RED << "Invalid index. Please try again." << RESET << std::endl;	
			break ;
		}
	}
	contact.printDetailedContact(contact);
}