UNAME_S = $(shell uname -s)

NAME = output

SRC = $(wildcard *.cpp)

CC = clang++

RM = rm -rf

OBJ = $(SRC:.cpp=.o)

HEADERS = $(wildcard *.hpp)

ifeq ($(UNAME_S), Linux)
	CPPFLAGS = -g -Wall -Wextra -Werror -I. -std=c++98
else
	CPPFLAGS = -Wall -Wextra -Werror -I. -std=c++98 -fsanitize=address
endif


all: $(NAME) run


$(NAME): $(OBJ) ${HEADERS} Makefile
	@$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[1;32mCompiled"

%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@
	@echo -n "\033[1;35m"

clean:
	@$(RM) $(OBJ)
	@echo "\033[1;31mClean"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[1;31mFclean"

re: fclean all

.PHONY: all clean fclean re run
