/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:28:31 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/04 17:33:30 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main(void) {
  PhoneBook book;
  Contact contact;
  Contact contacts[10];

  for (int i = 0; i < 10; i++) {
    contacts[i].set_nickname(std::to_string(i));
    std::cout << "Add contact: " << i << std::endl;
    book.add_contact(contacts[i]);

    std::cout << "-- Contacts --" << std::endl;
    for (int j = 0; j < book.get_num_contacts(); j++) {
      contact = book.get_contact(j);
      std::cout << "[" << j << "] " << contact.get_nickname() << std::endl;
    }
  }

  return 0;
}
