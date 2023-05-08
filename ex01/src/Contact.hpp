/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:40:23 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/08 10:37:18 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file Contact.hpp
 * @brief Declaration of the Contact class.
 */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

/**
 * @brief Represents a contact with first name, last name, nickname, phone
 * number, and darkest secret.
 */
class Contact {
public:
  /**
   * @brief Default constructor for Contact class.
   */
  Contact(void);

  /**
   * @brief Destructor for Contact class.
   */
  ~Contact(void);

  /**
   * @brief Setter for the first name of the contact.
   * @param first_name The new first name for the contact.
   */
  void set_first_name(std::string first_name);

  /**
   * @brief Setter for the last name of the contact.
   * @param last_name The new last name for the contact.
   */
  void set_last_name(std::string last_name);

  /**
   * @brief Setter for the nickname of the contact.
   * @param nickname The new nickname for the contact.
   */
  void set_nickname(std::string nickname);

  /**
   * @brief Setter for the phone number of the contact.
   * @param phone_number The new phone number for the contact.
   */
  void set_phone_number(std::string phone_number);

  /**
   * @brief Setter for the darkest secret of the contact.
   * @param darkest_secret The new darkest secret for the contact.
   */
  void set_darkest_secret(std::string darkest_secret);

  /**
   * @brief Getter for the first name of the contact.
   * @return The first name of the contact.
   */
  std::string get_first_name(void);

  /**
   * @brief Getter for the last name of the contact.
   * @return The last name of the contact.
   */
  std::string get_last_name(void);

  /**
   * @brief Getter for the nickname of the contact.
   * @return The nickname of the contact.
   */
  std::string get_nickname(void);

  /**
   * @brief Getter for the phone number of the contact.
   * @return The phone number of the contact.
   */
  std::string get_phone_number(void);

  /**
   * @brief Getter for the darkest secret of the contact.
   * @return The darkest secret of the contact.
   */
  std::string get_darkest_secret(void);

private:
  std::string first_name;     /**< The first name of the contact. */
  std::string last_name;      /**< The last name of the contact. */
  std::string nickname;       /**< The nickname of the contact. */
  std::string phone_number;   /**< The phone number of the contact. */
  std::string darkest_secret; /**< The darkest secret of the contact. */
};

#endif // !CONTACT_H
