##
## EPITECH PROJECT, 2022
## Arcade
## File description:
## Makefile
##

SRC	=	arcade.cpp

OBJ	=	$(SRC:.c=.o)

NAME	=	arcade

all	:	$(NAME)	$(SRC)
$(NAME)	:	$(OBJ)
	g++	-shared	-fPIC	pacman/pacman.cpp	-o	pacman.so
	g++	-shared	-fPIC	qix/qix.cpp	-o	qix.so
	g++	-shared	-fPIC	solarFox/solarFox.cpp	-o	solarFox.so
	gcc	-c	$(SRC)
	g++	-o	$(NAME)	*.o	-L.

clean	:
	rm	-f	*.o
	rm	-f	*.so
	rm	-f	*~

fclean	:	clean
	rm	-f	$(NAME)

re	:	fclean	all