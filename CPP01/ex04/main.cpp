/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:27:38 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/13 18:48:35 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include <iostream>
 #include <fstream>

void	event_loop(std::fstream &file, std::ofstream &new_file, const std::string &find, const std::string &replace) {

	std::string line;
	size_t	position;

	while (true)
	{
		std::getline(file, line);
		if (!file.good()) {
			break ;
		}
		do {
			position = line.find(find);
			if (position == std::string::npos) {
				new_file << line << std::endl;
				break ;
			}
			line.erase(position, find.length());
			line.insert(position, replace);
			new_file << line;
			if (!file.eof()) {
				new_file << std::endl;
			}
		} while (line.find(find) != std::string::npos);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error.\nInvalid arguments. It must be: ./sed <file.txt>"
		" <first string> <second string>" << std::endl;
		return (false);
	}

	std::string filename(argv[1]);
	std::string s1(argv[2]);
	std::string s2(argv[3]);

	std::fstream file(filename.c_str(), std::ios::in);
	if (!file.good()) {
		std::cout << "error: something went wrong with file openning" << std::endl;
		return (false);
	}
	std::ofstream new_file((filename + ".replace").c_str(),
	std::ios_base::app | std::ios_base::out);
	event_loop(file, new_file, s1, s2);
	file.close();
	new_file.close();
}
