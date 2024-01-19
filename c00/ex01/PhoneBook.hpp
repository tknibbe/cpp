/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tknibbe <tknibbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:03:56 by tknibbe           #+#    #+#             */
/*   Updated: 2024/01/19 16:03:37 by tknibbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PhoneBook_HPP
# define PhoneBook_HPP

#include "Contact.hpp"

class PhoneBook {
	
	private:
		Contact		contacts[8];
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	AddContact(void);
		void	SearchContact(void);
		void	PrintAll(void);
};

#endif
