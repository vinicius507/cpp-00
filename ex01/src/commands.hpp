/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:29:32 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/08 10:33:45 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include "PhoneBook.hpp"

typedef void (*t_cmd_handler)(PhoneBook &book);

void cmd_add(PhoneBook &book);

void cmd_search(PhoneBook &book);

#endif // !COMMANDS_HPP
