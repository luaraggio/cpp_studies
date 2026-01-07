/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:09:04 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/07 19:27:48 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class	Intern {
	private:
		AForm* createShrubbery(std::string target);
		AForm* createRobotomy(std::string target);
		AForm* createPresidential(std::string target);

	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& rhs);
		~Intern();

		AForm* makeForm(std::string formName, std::string formTarget);
};

#endif
