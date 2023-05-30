UNAME_S = $(shell uname -s)

NAME =  PmergeMe

SRC = $(wildcard *.cpp)

CC = c++

RM = rm -rf

OBJ = $(SRC:.cpp=.o)

HEADERS = $(wildcard *.hpp)

ifeq ($(UNAME_S), Linux)
	CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -I.
else
	CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -I.
endif

all: $(NAME)

$(NAME): $(OBJ) Makefile $(HEADERS)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo ""
	@echo "\033[1;32mCompiled"

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@
	@echo -n "\033[1;35m♥"==

clean:
	$(RM) $(OBJ)
	@echo "\033[1;31mClean"

fclean: clean
	$(RM) $(NAME)
	@$(RM) test1
	@echo "\033[1;31mFclean"

re: fclean all

.PHONY: all clean fclean re