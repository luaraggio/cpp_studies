/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:51:46 by lraggio           #+#    #+#             */
/*   Updated: 2025/04/08 13:19:41 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::~PhoneBook() {};

PhoneBook::PhoneBook()
{
	int	position;
	int	position;

	this->index = 0;
};

void PhoneBook::addContact(Contact contact)
{
	int	position;

	position = this->index % 8;
	this->contacts[position] = contact;
	this->index++;
	std::cout << "Contact added at position " << this->index + 1 << std::endl;
}

void    print_phonebook()
{
    std::cout << "\n📖 Phonebook Contacts:\n";
	std::cout << "--------------------------------------------\n";
	std::cout << "| Index | First Name | Last Name | Nickname |\n";
	std::cout << "--------------------------------------------\n";
}

void PhoneBook::displayAllContacts() const
{
    int i;

    i = 0;
    print_phonebook();
    while(i < 8)
    {
		this->contacts[this->index].printContact();
        i++;
    }
}
