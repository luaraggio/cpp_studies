/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HarlFilter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:42:28 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/13 09:44:37 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARLFILTER_HPP
# define HARLFILTER_HPP

# define CALL_MEMBER_FN(object,ptrToMember)  ((object).*(ptrToMember))
# include <iostream>

class HarlFilter {
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		std::string	message_list[4];
		void	(HarlFilter::*log_methods[4]) (void);
	public:
		HarlFilter();
		~HarlFilter();
		void	complain(std::string level);
};

#endif
