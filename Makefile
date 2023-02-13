##
## EPITECH PROJECT, 2020
## makefile
## File description:
## Makefile
##

CFLAGS = -g3 -W -Wall -Wextra -I./include

SRC = source/mysh.c \
	source/parsing.c \
	source/path.c \
	source/command.c \
	source/exec.c \
	source/binary.c \
	source/signals.c \
	source/builtins.c \
	source/environment.c \
	source/cd.c \
	source/setenv.c

OBJ = $(SRC:.c=.o)

NAME = mysh

all:  $(NAME) clean

$(NAME): $(OBJ)
	cd lib/my/ && make
	cd ../../
	gcc -o $(NAME) $(OBJ) -L./lib -lmy

clean:
	cd lib/my && make clean
	cd ../../
	rm -f $(OBJ)

fclean: clean
	cd lib/my && make fclean
	cd ../../
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re