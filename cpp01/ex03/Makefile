CXX := g++
NAME := weapons
CXXFLAGS := -Wall -Werror -Wextra -std=c++98 -g
SRCS =	Weapon.cpp\
		HumanA.cpp\
		HumanB.cpp\
		main.cpp\

OBJS = $(SRCS:.cpp=.o)

# COLORS #

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
GREY = \033[2;37m
MAGENTA = \033[0;35m
CURSIVE = \033[3m
NO_COLOR = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "\033[0;32mCompiled\033[0m"

echo: 
	echo $(OBJS)

clean:
	@rm -rf $(NAME)
	@echo "\033[0;33mCleaning executable\033[0m"

fclean: clean
	@rm -rf $(OBJS)
	@echo "\033[0;35mFclean done\033[0m"

re: fclean all
