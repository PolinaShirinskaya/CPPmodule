NAME	= serialize

SRCS	= $(wildcard *.cpp)

HEADERS = Data.hpp

CC		= c++

FLAGS	= -Wall -Wextra -Werror -std=c++98 -I.

RM		= rm -f

OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
		@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
		@echo "\033[1;35mCompiled"

%.o: %.cpp
		@$(CC) $(FLAGS) -c $< -o $@

clean:
		@$(RM) $(OBJS)
		@echo "\033[1;34mClean"

fclean: clean
		@$(RM) $(NAME)
		@echo "\033[1;34mFclean"

re: fclean all

.PHONY: all clean fclean re
