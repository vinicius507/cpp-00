/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:28:31 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/07 22:47:57 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
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

static void border(void) {
  int cols = 4;

  for (int i = 0; i < cols; i++) {
    std::cout << "+" << std::setw(11) << std::setfill('-');
  }
  std::cout << "+" << std::endl;
}

static void cell(std::string content) {
  std::cout << "|" << std::setw(10) << std::setfill(' ') << content;
}

static void endofrow(void) { std::cout << "|" << std::endl; }

static void header(void) {
  cell("Id");
  cell("First Name");
  cell("Last Name");
  cell("Nickname");
  endofrow();
}

static void search_display_contacts(PhoneBook &book) {
  border();
  header();
  border();
  (void)book;
}

static void cmd_search(PhoneBook &book) { search_display_contacts(book); }

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
