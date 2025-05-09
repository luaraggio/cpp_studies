/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:57:39 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/07 11:17:00 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "Contact.hpp"
# include <iostream>
# include <cctype>
# include <iomanip>
# include <string>

class Contact
{
  private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

  public:
	Contact(void);
	~Contact(void);
	std::string	getFirstName() const;
	std::string getLastName()	const;
	std::string getNickname()	const;
	std::string getPhoneNumber()	const;
	std::string getDarkestSecret()	const;
	void setFirstName();
	void setLastName();
	void setNickname();
	void setPhoneNumber();
	void setDarkestSecret();
	void setContact();
	void	printDetailedContact() const;
	void	printContacts() const;
};

std::string format_string(std::string input);
std::string format_string_table(std::string name);
bool	has_only_letters(std::string input);
bool	has_only_numbers(std::string input);
bool	is_valid_input(std::string input, const std::string type);

#endif
