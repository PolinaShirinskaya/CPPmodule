NAME	= megaphone

SRCS	= megaphone.cpp

OBJS	= $(SRCS:.cpp=.o)

CC		= clang++

FLAGS	= -Wall -Wextra -Werror -std=c++98

RM		= rm -f

all: $(NAME)

$(NAME): $(OBJS)
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
