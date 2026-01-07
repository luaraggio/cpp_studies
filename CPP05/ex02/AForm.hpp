/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:51:39 by lraggio           #+#    #+#             */
/*   Updated: 2025/12/30 11:07:36 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORMHPP
# define AFORMHPP

# include <iostream>
# include <exception>

class	Bureaucrat;

class	AForm {
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;
	public:
		AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
		virtual ~AForm();
		AForm(const AForm& other);
		AForm& operator=(const AForm& rhs);
		void beSigned(const Bureaucrat& b);
		std::string	getName() const;
		bool getIsSignedOrNot() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void	execute(Bureaucrat const & executor) const;
		virtual void executeAction() const = 0;

		class	GradeTooHighException: public std::exception {
			public:
				const char *what() const throw();
		};

		class	GradeTooLowException: public std::exception {
			public:
				const char *what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				const char * what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& b);

#endif
