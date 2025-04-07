/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:57:39 by lraggio           #+#    #+#             */
/*   Updated: 2025/04/07 17:33:23 by lraggio          ###   ########.fr       */
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
	void setFirstName();
	void setLastName();
	void setNickname();
	void setPhoneNumber();
	void setDarkestSecret();
	void setContact();
	void printContact() const;
	std::string Contact::getFirstName() const;
	std::string Contact::getLastName()	const;
	std::string Contact::getNickname()	const;
	std::string Contact::getPhoneNumber()	const;
	std::string Contact::getDarkestSecret()	const;
};

std::string format_string(std::string input);
bool	has_only_letters(std::string input);
bool	has_only_numbers(std::string input);
bool	is_valid_input(std::string input, const std::string type);

#endif
