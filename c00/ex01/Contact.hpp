/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tknibbe <tknibbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:04:07 by tknibbe           #+#    #+#             */
/*   Updated: 2023/12/06 15:32:29 by tknibbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact {
	private:
		std::string	first_name;
		std::string	last_name;
		std::string nickname;
		std::string	phone_number;
		std::string	secret;
	public:
		Contact(void);
		~Contact(void);
		void	set_contact();
		void	print();
		void	print_ui(int index);
};

#endif