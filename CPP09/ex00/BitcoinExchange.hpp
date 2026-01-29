/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:27:26 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/28 21:47:28 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>

class	BitcoinExchange {
	private:
		std::map<std::string, double> _rates;
		double getRateForDate(const std::string& date) const;
		bool isValidValue(const std::string& valueStr, double& value) const;
		bool isValidDate(const std::string& date) const;
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange& operator=(const BitcoinExchange &rhs);

		void parseInputFile(const std::string& filename);
		void parseDatabase(const std::string& filename);
};

#endif
