/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:51:46 by lraggio           #+#    #+#             */
/*   Updated: 2025/03/20 01:30:56 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	int	position;
	int	position;

	this->index = 0;
};
PhoneBook::~PhoneBook() {};
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

std::string Contact::getFirstName() const
{
    return (this->firstName);
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
