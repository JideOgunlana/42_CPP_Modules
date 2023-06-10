# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 13:41:42 by bogunlan          #+#    #+#              #
#    Updated: 2023/05/24 06:39:45 by bogunlan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex00

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 #-g -fsanitize=address

DEPFLAGS = -MMD -MP -MF $(DEPS_DIR)/$*.d

VPATH = ./ src/

SRCS = main.cpp Bureaucrat.cpp

OBJS_DIR = obj
OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.cpp=.o)))

DEPS_DIR = dep
DEPS = $(addprefix $(DEPS_DIR)/, $(notdir $(SRCS:.cpp=.d)))

# Graphical
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[1;32m
LGREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[1;34m
LBLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
RESET = \e[0m
UP = "\033[A"
CUT = "\033[K"


all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $@
	@printf "%-54b %b" "$(NAME) $(GREEN) compiled succesfully!" "$(GREEN)[√]$(RESET)\n"
	
	
$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR) $(DEPS_DIR)
	@$(CC) $(FLAGS) $(DEPFLAGS) -c $< -o $@
	@printf "%-61b %b" "$(BLUE)compiling: $(LBLUE)$@" "$(GREEN)[√]$(RESET)\n"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(DEPS_DIR):
	@mkdir -p $(DEPS_DIR)

clean:
	@$(RM) -fr $(OBJS_DIR) $(DEPS_DIR)
	@printf "$(NAME) $(YELLOW) cleaned! $(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(RED)Full Clean complete $(RESET)\n"

re: clean all

.PHONY: all clean fclean re
-include $(DEPS)