/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_add.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:30:44 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/08 10:33:22 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.hpp"
#include "prompt.hpp"

void cmd_add(PhoneBook &book) {
  Contact ctt;

  std::cout << "Add a contact" << std::endl;

  ctt.set_first_name(prompt("First name: "));
  ctt.set_last_name(prompt("Last name: "));
  ctt.set_nickname(prompt("Nickname: "));
  ctt.set_phone_number(prompt("Phone number: "));
  ctt.set_darkest_secret(prompt("Darkest secret: "));

  book.add_contact(ctt);
}
