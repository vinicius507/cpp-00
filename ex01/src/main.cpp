/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:28:31 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/09 08:37:36 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "commands.hpp"
#include "prompt.hpp"

static t_cmd_handler get_cmd_handler(std::string cmd) {
  if (cmd == "ADD")
    return (cmd_add);
  if (cmd == "SEARCH")
    return (cmd_search);
  return (NULL);
}

int main(void) {
  PhoneBook book;
  std::string cmd;
  t_cmd_handler handler;

  std::cout << "Welcome to the Phonebook CLI tool!" << std::endl
            << "You can use the following commands:" << std::endl
            << "  ADD       Adds a contact to the Phonebook" << std::endl
            << "  SEARCH    Views information about a contact" << std::endl
            << "  EXIT      Exits the application" << std::endl;

  do {
    cmd = prompt("\nphonebook# ");

    if (cmd == "EXIT")
      break;

    handler = get_cmd_handler(cmd);

    if (handler == NULL) {
      std::cerr << "Unknown command: " << cmd << std::endl;
      continue;
    }

    handler(book);
  } while (1);
  return 0;
}
