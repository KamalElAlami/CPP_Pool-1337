NAME = ex02

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g
HEADER = Animal.hpp WrongAnimal.hpp Cat.hpp WrongCat.hpp Dog.hpp Brain.hpp
 
SRC = main.cpp Animal.cpp WrongAnimal.cpp Cat.cpp WrongCat.cpp Dog.cpp Brain.cpp

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