/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tknibbe <tknibbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:03:56 by tknibbe           #+#    #+#             */
/*   Updated: 2023/10/14 16:05:11 by tknibbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PhoneBook_HPP
# define PhoneBook_HPP

#include "Contact.hpp"

class PhoneBook {
	int test;
	private:
		Contact		contacts[8];
		// int			contact_count = 0;
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add_contact();
		void	search_contact();

};

#endif
