# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stmartin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/04 14:21:39 by stmartin          #+#    #+#              #
#    Updated: 2016/09/20 17:52:50 by stmartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
SRC_PUSH_PATH = ./src2/
OBJ_PATH = ./obj/
OBJ_PUSH_PATH = ./obj2/
INC_PATH = ./include/ ./libft/
LIB_PATH = ./libft/

SRC_NAME = main.c parsing.c manip_pile.c list.c
SRC_PUSH_NAME = main.c

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PUSH_NAME = $(SRC_PUSH_NAME:.c=.o)
LIB_NAME = -lft
NAME = checker
NAME_PUSH = push_swap

#SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
OBJ_PUSH = $(addprefix $(OBJ_PUSH_PATH),$(OBJ_PUSH_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L,$(LIB_PATH))

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror

all: lib
	@echo "\033[37;44m Make $(NAME) \033[0m"
	@make $(NAME)
	@echo "\033[37;44m Make $(NAME_PUSH) \033[0m"
	@make $(NAME_PUSH)

$(NAME): $(OBJ)
	$(CC) $(INC) $^ -o $@ $(LIB) $(LIB_NAME)

$(NAME_PUSH): $(OBJ_PUSH)
	$(CC) $(INC) $^ -o $@ $(LIB) $(LIB_NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ_PUSH_PATH)%.o: $(SRC_PUSH_PATH)%.c
	@mkdir -p $(OBJ_PUSH_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<
.PHONY: lib clean fclean re

lib:
	@echo "\033[37;44m Make libft \033[0m"
	@make -C ./libft/

clean:
	rm -rf $(OBJ) $(OBJ_PATH) $(OBJ_PUSH_PATH)

fclean: clean
	rm -f $(NAME) $(NAME_PUSH)
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
