##
## EPITECH PROJECT, 2022
## Arcade
## File description:
## Makefile
##

SRC	=	arcade.cpp

SRCC	=	pacman/pacman.c	\
			qix/qix.c	\
			solarFox/solarFox.c

OBJ	=	$(SRC:.c=.o)

NAME	=	arcade

all	:	$(NAME)	$(SRC)
$(NAME)	:	$(OBJ)
	gcc	-c	-fPIC	$(SRCC)
	gcc	-shared	-o	lib.so	$(OBJ)
	gcc	-c	$(SRC)
	g++	-o	$(NAME)	*.o	-L.	lib.so

clean	:
	rm	-f	*.o
	rm	-f	*.so
	rm	-f	*~

fclean	:	clean
	rm	-f	$(NAME)

re	:	fclean	all