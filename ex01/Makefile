# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 16:22:43 by vgoncalv          #+#    #+#              #
#    Updated: 2023/05/08 10:35:46 by vgoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=phonebook

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRC_DIR := ./src
BUILD_DIR = ./build

SRCS := main.cpp Contact.cpp PhoneBook.cpp cmd_add.cpp cmd_search.cpp prompt.cpp

OBJS := $(addprefix $(BUILD_DIR)/,$(SRCS:%.cpp=%.o))
SRCS := $(addprefix $(SRC_DIR)/,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
