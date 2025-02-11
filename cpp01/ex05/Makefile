# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 10:49:03 by kael-ala          #+#    #+#              #
#    Updated: 2025/02/11 05:55:37 by kael-ala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = HARL
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Harl.cpp  
OBJ = $(SRC:.cpp=.o)
HEADER = Harl.hpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re