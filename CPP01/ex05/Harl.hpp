/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 19:19:08 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/12 19:04:46 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# define CALL_MEMBER_FN(object,ptrToMember)  ((object).*(ptrToMember))
# include <iostream>

class Harl {
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		std::string	message_list[4];
		void	(Harl::*log_methods[4]) (void);
	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};

#endif
