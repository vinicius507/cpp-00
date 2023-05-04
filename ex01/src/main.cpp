/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:28:31 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/04 17:01:30 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <ostream>

int main(void) {
  Contact contact;

  contact.set_first_name("Vinicius");
  contact.set_last_name("Oliveira");
  contact.set_nickname("Dezano");
  contact.set_phone_number("+5583999999999");
  contact.set_darkest_secret("I am Dezano");

  std::cout << contact.get_first_name() << " " << contact.get_last_name()
            << std::endl;
  std::cout << contact.get_nickname() << std::endl;
  std::cout << contact.get_phone_number() << std::endl;
  std::cout << contact.get_darkest_secret() << std::endl;
  return 0;
}
