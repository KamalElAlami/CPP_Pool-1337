# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dedsec <dedsec@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 10:49:03 by kael-ala          #+#    #+#              #
#    Updated: 2025/01/08 19:18:51 by dedsec           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Replace
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp sedForLosers.cpp  
OBJ = $(SRC:.cpp=.o)
HEADER = sedForLosers.hpp

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