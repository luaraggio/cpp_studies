/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:51:46 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/07 11:36:01 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {};

PhoneBook::~PhoneBook() {};

void PhoneBook::addContact(Contact contact)
{
	int	position;

	position = this->index % 8;
	contact.setContact();
	this->contacts[position] = contact;
	if (this->numberOfContacts < 8)
		this->numberOfContacts++;
	std::cout << "Contact added at position " << position + 1 << std::endl;
	this->index++;
}

void PhoneBook::searchContact()
{
	std::string input;
	int	index;

	index = 0;
	std::cout << "🔎 Enter the index number of the contact"
	 "you want to view in detail:" << std::endl;
	std::getline(std::cin, input);
	while (!is_valid_search_input(input))
	{
		std::cout << "You must enter the index number of the contact"
		 "you want to view in detail." << std::endl;
		std::getline(std::cin, input);
	}
	index = std::stoi(input);
	if (index >= 0 && index < numberOfContacts)
		contacts[index].printDetailedContact();
	else
		std::cout << "❌ No contact found at index " << index << std::endl;
}

void    print_phonebook()
{
	std::cout << "|" << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "FirstName";
	std::cout << "|" << std::setw(10) << "LastName";
	std::cout << "|" << std::setw(10) << "Nickname";
	std::cout << "|" << std::endl;
}

void PhoneBook::displayAllContacts() const
{
	if (numberOfContacts == 0)
	{
		std::cout << "PhoneBook is empty." << std::endl;
		return ;
	}
	print_phonebook();
	for (int i = 0; i < numberOfContacts; i++) {
		std::cout << "|" << std::setw(10) << i + 1;
		contacts[i].printContacts();
	}
}
