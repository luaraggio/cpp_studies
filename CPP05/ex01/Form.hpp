/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:51:39 by lraggio           #+#    #+#             */
/*   Updated: 2025/11/24 15:26:52 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>

class	Bureaucrat;

class	Form {
	private:
		const std::string _name;
		bool _isSignedOrNot;
		const int _gradeToSign;
		const int _gradeToExecute;
	public:
		Form(const std::string name, const int gradeToSign, const int gradeToExecute);
		~Form();
		Form(const Form& other);
		Form& operator=(const Form& rhs);
		void beSigned(const Bureaucrat&);
		std::string	getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;


		class	GradeTooHighException: public std::exception {
			public:
				const char *what() const throw();
		};

		class	GradeTooLowException: public std::exception {
			public:
				const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& b);

#endif
