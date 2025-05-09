/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:27:05 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/09 15:10:26 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	print_phonebook_welcome()
{
	std::cout << PURPLE "Hi, welcome back to 80s and their unbelievable technology! :D\n" RESET;
	std::cout << PURPLE "You just found My Awesome PhoneBook.\n" RESET;
}

void	phonebook_loop()
{
	PhoneBook	phonebook;
	Contact		contact;
	std::string	command;

	while (42)
	{
		std::cout << "Enter ADD, SEARCH or EXIT." << std::endl;
		std::getline(std::cin, command);
		if (command == "ADD" || command == "add")
		{
			std::cout << BLUE "Adding a contact to PhoneBook" RESET << std::endl;
			phonebook.addContact(contact);
		}
		else if (command == "SEARCH" || command == "search")
		{
			std::cout << BLUE "Searching a contact in PhoneBook" RESET << std::endl;
			phonebook.displayAllContacts();
		}
		else if (command == "EXIT" || command == "exit")
		{
			std::cout << BLUE "Goodbye! (:" RESET << std::endl;
			break ;
		}
		else
			std::cout << RED "Invalid command. Use ADD, SEARCH or EXIT." RESET << std::endl;
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		std::cout << "Error.\nWrong argument." << std::endl;
		return (1);
	}
	print_phonebook_welcome();
	phonebook_loop();
	return (0);
}
