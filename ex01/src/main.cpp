/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:28:31 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/07 22:16:53 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

typedef void (*t_cmd_handler)(PhoneBook &book);

static std::string prompt(std::string prefix) {
  std::string ans;

  std::cout << prefix;
  std::getline(std::cin, ans);

  if (std::cin.eof()) {
    std::cerr << std::endl << "error: EOF reached while reading standard input";
    exit(1);
  }

  if (std::cin.fail()) {
    std::cerr << "error: input failure while reading standard input";
    exit(1);
  }
  return ans;
}

static void cmd_add(PhoneBook &book) {
  Contact ctt;

  std::cout << "Add a contact" << std::endl;

  ctt.set_first_name(prompt("First name: "));
  ctt.set_last_name(prompt("Last name: "));
  ctt.set_nickname(prompt("Nickname: "));
  ctt.set_phone_number(prompt("Phone number: "));
  ctt.set_darkest_secret(prompt("Darkest secret: "));

  book.add_contact(ctt);
}

static t_cmd_handler get_cmd_handler(std::string cmd) {
  if (cmd == "ADD") {
    return (cmd_add);
  }
  return (NULL);
}

int main(void) {
  PhoneBook book;
  std::string cmd;
  t_cmd_handler handler;

  do {
    cmd = prompt("phonebook# ");

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
