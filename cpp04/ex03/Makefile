NAME = ex03

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
HEADER = AMateria.hpp Character.hpp ICharacter.hpp Cure.hpp Ice.hpp IMateriaSource.hpp MateriaSource.hpp
 
SRC = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp

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