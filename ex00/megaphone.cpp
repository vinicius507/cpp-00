/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:04:33 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/04/12 20:19:15 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
  }

  for (int i = 1; i < argc; i++) {
    for (int j = 0; argv[i][j] != '\0'; j++) {
      std::cout << (char)std::toupper(argv[i][j]);
    }
  }
  std::cout << std::endl;
  return (0);
}
