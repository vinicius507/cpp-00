/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:32:21 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/08 10:44:20 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file prompt.hpp
 * @brief Prompt helper function header file.
 */

#ifndef PROMPT_HPP
#define PROMPT_HPP

#include <string>

/**
 * @brief Shows a prompt with a `prefix` and captures a line from standard
 * input.
 *
 * @param prefix The prompt prefix.
 * @return The input of the user.
 */
std::string prompt(std::string prefix);

#endif // !PROMPT_HPP
