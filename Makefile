# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/07 15:07:30 by negambar          #+#    #+#              #
#    Updated: 2024/12/09 17:00:27 by alerusso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = hello_world

SRC = main.c

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
# MINILBX = -Lminilibx-linux -lmlx -lXext -lX11 -lm

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@echo Linking... $(NAME)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS) 
#		$(MINILBX)
%.o:%.c
	@echo Compiling $<...
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		@echo Cleaning...
		@rm -f $(OBJ)
fclean: clean
		@echo Cleaning...
		rm -f $(NAME)
crash: fclean $(NAME); make clean
re: fclean all
.PHONY: clean fclean re all
.SILENT: