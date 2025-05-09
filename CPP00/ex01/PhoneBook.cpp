/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:51:46 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/09 16:02:35 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->index = 0;
	this->numberOfContacts = 0;
};
PhoneBook::~PhoneBook(){};
void PhoneBook::addContact(Contact contact)
{
	contact.setContact();
	if (this->numberOfContacts == 8 && this->index == 8)
		this->index = 0;
	this->contacts[index] = contact;
	std::cout << "Contact added at position " << index + 1 << std::endl;
	if (this->numberOfContacts < 8)
		this->numberOfContacts++;
	this->index++;
}

void PhoneBook::searchContact()
{
	int	index;

	std::string input;
	index = 0;
	std::cout << "🔎 Enter the index number of the contact "
					"you want to view in detail:"
				<< std::endl;
	std::getline(std::cin, input);
	while (!is_valid_search_input(input))
	{
		std::cout << "You must enter the index number of the contact "
						"you want to view in detail."
					<< std::endl;
		std::getline(std::cin, input);
	}
	index = input[0] - '0';
	index--;
	if (index >= 0 && index < numberOfContacts)
		contacts[index].printDetailedContact();
	else
		std::cout << "❌ No contact found at index " << index << std::endl;
}

void	print_phonebook(void)
{
	std::cout << "|" << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "FirstName";
	std::cout << "|" << std::setw(10) << "LastName";
	std::cout << "|" << std::setw(10) << "Nickname";
	std::cout << "|" << std::endl;
}

void PhoneBook::displayAllContacts()
{
	if (numberOfContacts == 0)
	{
		std::cout << "PhoneBook is empty." << std::endl;
		return ;
	}
	print_phonebook();
	for (int i = 0; i < numberOfContacts; i++)
	{
		std::cout << "|" << std::setw(10) << i + 1;
		contacts[i].printContacts();
	}
	searchContact();
}
