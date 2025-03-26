/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:19:46 by lraggio           #+#    #+#             */
/*   Updated: 2025/03/20 01:13:34 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include "iostream"
# include <iomanip>
# include <string>

# define PURPLE "\033[35m"
# define RESET "\033[0m"
# define RED "\033[31m"
# define BLUE "\033[34m"

class PhoneBook
{
  private:
	Contact contacts[8];
	int index;
	int numberOfContacts;

  public:
	PhoneBook(void);
	~PhoneBook(void);
	void addContact(Contact contact);
	void displayAllContacts() const;
	void searchContact();
	//void displayContact();
};

#endif
