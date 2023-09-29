/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tknibbe <tknibbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:03:56 by tknibbe           #+#    #+#             */
/*   Updated: 2023/09/29 12:03:57 by tknibbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Phonebook {
	int test;
	private:
		Contact		contacts[8];
		int			contact_count;
	public:
		void	add_contact();
		void	search_contact();
};

