/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:11:35 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/04 17:33:04 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook(void) { this->num_contacts = 0; };

PhoneBook::~PhoneBook(void) { return; };

int PhoneBook::get_num_contacts(void) { return this->num_contacts; }

Contact &PhoneBook::get_contact(int index) {
  if (index < 0 || index >= this->num_contacts) {
    return ((Contact &)EMPTY_CONTACT);
  }
  return (this->contacts[index]);
};

void PhoneBook::add_contact(Contact contact) {
  static int i;

  if (this->num_contacts < 8) {
    this->num_contacts++;
  }

  this->contacts[i] = contact;
  i = (i + 1) % 8;
}
