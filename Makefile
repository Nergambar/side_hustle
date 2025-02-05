# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/07 15:07:30 by negambar          #+#    #+#              #
#    Updated: 2025/02/04 13:54:11 by alerusso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = hello_world

FILE_UTILS = get_next_line_sideft/manage_file_ft.a

SRC = gnl.c get_next_line_utils.c main.c initial_utils.c ft_strtrim.c \
	utils.c \
	second_step.c \
	get_next_line_sideft/get_next_line_bonus.c \
	get_next_line_sideft/get_next_line_utils_bonus.c \
	get_next_line_sideft/ft_itoa.c \
	get_next_line_sideft/ft_memset.c \
	get_next_line_sideft/ft_memcmp.c get_next_line_sideft/main.c

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
# MINILBX = -Lminilibx-linux -lmlx -lXext -lX11 -lm

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@echo Linking... $(NAME)
		$(CC) $(OBJ) $(FILE_UTILS) -o $(NAME) $(CFLAGS) 
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