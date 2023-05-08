/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:29:32 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/08 10:47:40 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file commands.hpp
 * @brief Command handlers for the phonebook cli tool.
 */

#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include "PhoneBook.hpp"

typedef void (*t_cmd_handler)(PhoneBook &book);

/**
 * @brief Command handler for the ADD command.
 *
 * The ADD command adds a Contact to the PhoneBook. It retrieves the Contact
 * information via standard input.
 *
 * @param book The phonebook instance.
 */
void cmd_add(PhoneBook &book);

/**
 * @brief Command handler for the SEARCH command.
 *
 * The SEARCH command prints a table with all contacts fields "Id", "First
 * Name", "Last Name" and "Nickname" and prompts the user to select a contact.
 *
 * After selecting a contact, the contact information is displayed to the user.
 *
 * @param book The phonebook instance.
 */
void cmd_search(PhoneBook &book);

#endif // !COMMANDS_HPP
