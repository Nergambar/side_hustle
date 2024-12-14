NAME = readfile.a
CP = cp
SRC = 	
OBJ = $(SRC:.c=.o)
COMP = cc -Wall -Werror -Wextra -g

gdb: 
	$(COMP) libft.a main.c $(SRC)
	clear
	gdb ./a.out

run:
	$(COMP) libft.a main.c $(SRC)
	clear
	./a.out

val:
	$(COMP) libft.a main.c $(SRC)
	clear
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out

.PHONY: all clean fclean re main gdb val run
