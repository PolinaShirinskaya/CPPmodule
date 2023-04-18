NAME			= intern

CC				= clang++

FLAGS			= -Wall -Wextra -Werror -std=c++98 -ggdb -fsanitize=address -fsanitize=leak

RM				= rm -rf

HEADERS_DIR 	= includes

HEADERS_LIST	=	AForm.hpp \
					Bureaucrat.hpp \
					ShrubberyCreationForm.hpp \
					RobotomyRequestForm.hpp \
					PresidentialPardonForm.hpp \
					Intern.hpp

HEADERS			=	$(addprefix $(HEADERS_DIR)/,$(HEADERS_LIST))

SRCS_DIR		=	srcs

SRCS_LIST		=	AForm.cpp \
					Bureaucrat.cpp \
					ShrubberyCreationForm.cpp \
					RobotomyRequestForm.cpp \
					PresidentialPardonForm.cpp \
					Intern.cpp \
					main.cpp

SRCS		=	$(addprefix $(OBJS_DIR)/,$(SRCS_LIST))

OBJS_DIR	=	objs

OBJS		=	$(addprefix $(OBJS_DIR)/,$(SRCS_LIST:.cpp=.o))

NORMAL			=	\033[0m
RED				=	\033[1;31m
GREEN			=	\033[1;32m
YELLOW			=	\033[1;33m
BLUE			=	\033[1;34m
CYAN			=	\033[1;36m
WHITE			=	\033[1;37m


all : $(OBJS_DIR) $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)Project succesfully compiled$(NORMAL)"

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.cpp $(HEADERS) Makefile
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BLUE)Creating object file$(WHITE) --> $(notdir $@) --> $(GREEN)[Done]$(NORMAL)"

$(OBJS_DIR) :
	@mkdir -p objs
	@echo "$(CYAN)Creating directory for objects file:$(WHITE) $(GREEN)[Done]$(NORMAL)"

clean :
	@$(RM) $(OBJS_DIR)
	@echo "$(YELLOW)Removing objects files$(WHITE) --> *.o --> $(GREEN)[Done]$(NORMAL)"

fclean : clean
	@$(RM) $(NAME)
	@echo "$(YELLOW)Removing perfoming file$(WHITE) --> $(NAME) --> $(GREEN)[Done]$(NORMAL)"

re : fclean all

.PHONY: all clean fclean re
