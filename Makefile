# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stmartin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/04 14:21:39 by stmartin          #+#    #+#              #
#    Updated: 2016/09/07 14:37:13 by stmartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/ ./libft/
LIB_PATH = ./libft/

SRC_NAME = main.c parsing.c manip_pile.c list.c

OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = -lft
NAME = checker

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L,$(LIB_PATH))

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror

all: lib
	@echo "\033[37;44m Make $(NAME) \033[0m"
	@make $(NAME)

$(NAME): $(OBJ)
		$(CC) $(INC) $^ -o $@ $(LIB) $(LIB_NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<
.PHONY: lib clean fclean re

lib:
	@echo "\033[37;44m Make libft \033[0m"
	@make -C ./libft/

clean:
	rm -rf $(OBJ) $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)
	@make -C ./libft/ fclean

re: fclean
	@$(MAKE) all

norme :
	@echo "\033[37;44m norme libft \033[0m"
	@norminette ./libft/*[ch]
	@echo "\033[37;44m norme src directory \033[0m"
	@norminette ./src/*.c
	@echo "\033[37;44m norme include directory \033[0m"
	@norminette ./include/*.h
