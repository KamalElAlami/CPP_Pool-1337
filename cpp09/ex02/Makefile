NAME = PmergeMe

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address
HEADER = PmergeMe.hpp
 
SRC = main.cpp PmergeMe.cpp PmergeMeDeque.cpp

OBJ = $(SRC:.cpp=.o)

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