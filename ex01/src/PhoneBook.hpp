/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:02:12 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/08 10:37:26 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file PhoneBook.hpp
 * @brief Declaration of the PhoneBook class.
 */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

/**
 * @brief Represents a phone book with an array of contacts.
 */
class PhoneBook {
public:
  /**
   * @brief Default constructor for PhoneBook class.
   */
  PhoneBook(void);

  /**
   * @brief Destructor for PhoneBook class.
   */
  ~PhoneBook(void);

  /**
   * @brief Gets the total number of contacts in the phone book.
   * @return The number of contacts.
   */
  int get_num_contacts(void);

  /**
   * @brief Gets a contact at the specified index.
   * @param index The index of the contact to retrieve.
   * @return The contact at the specified index.
   */
  Contact &get_contact(int index);

  /**
   * @brief Adds a new contact to the phone book.
   * @param contact The new contact to add.
   */
  void add_contact(Contact contact);

private:
  static const int MAX_CONTACTS = 8; /**< The maximum number of contacts that
                                        can be stored in the phone book. */
  Contact
      contacts[MAX_CONTACTS]; /**< The array of contacts in the phone book. */
  int num_contacts; /**< The current number of contacts in the phone book. */
  const Contact EMPTY_CONTACT; /**< Sentinel value for an empty contact. */
};

#endif // !PHONEBOOK_H
