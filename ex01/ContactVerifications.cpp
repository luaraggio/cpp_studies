/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactVerifications.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:06:52 by lraggio           #+#    #+#             */
/*   Updated: 2025/04/09 13:43:47 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string format_string_table(std::string name)
{
	if (name.length() > 10)
	{
		name = name.substr(0, 9);
		name += ".";
	}
	else
	{
		while (name.length() < 10)
			name += " ";
	}
	return (name);
}

std::string format_string(std::string input)
{
	int	i;

	std::string formated_string;
	i = 0;
	while (input[i])
	{
		if (i == 0)
			formated_string += toupper(input[i]);
		else if (input[i] == ' ' && isalpha(input[i + 1]))
		{
			formated_string += input[i];
			i++;
			formated_string += toupper(input[i]);
		}
		else
			formated_string += tolower(input[i]);
		i++;
	}
	return (formated_string);
}

bool	has_only_letters(std::string input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (!(input[i] == ' ') && !isalpha(input[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	has_only_numbers(std::string input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (!(isdigit(input[i])))
			return (false);
		i++;
	}
	return (true);
}

bool	is_valid_input(std::string input, const std::string type)
{
	if (input.empty())
	{
		std::cout << "❌ The field " << type << "cannot be empty" << std::endl;
		return (false);
	}
	if (type == "'Nickname'")
	{
		if (input.length() < 5)
		{
			std::cout << "❌ The field " << type << "must have at least 5 characters" << std::endl;
			return (false);
		}
	}
	if (type == "'First Name'" || type == "'Last Name'")
	{
		if (!has_only_letters(input))
		{
			std::cout << "❌ The field " << type << "must only contain letters" << std::endl;
			return (false);
		}
	}
	if (type == "'Phone Number'")
	{
		if (!has_only_numbers(input))
		{
			std::cout << "❌ The field " << type << "must only contain numbers" << std::endl;
			return (false);
		}
		if (input.length() != 11)
		{
			std::cout << "❌ The field " << type << "must have 11 numbers: DDD9XXXXXXXX" << std::endl;
			return (false);
		}
	}
	return (true);
}
