##
## EPITECH PROJECT, 2022
## Arcade
## File description:
## Makefile
##

SRC	=	arcade.cpp

OBJ	=	$(SRC:.c=.o)

CXX	=	-Wall	-Wextra	-std=c++20

NAME	=	arcade

all	:	$(NAME)	$(SRC)
$(NAME)	:	$(OBJ)
	g++	-shared	-fPIC	game/pacman/pacman.cpp	-o	pacman.so
	g++	-shared	-fPIC	game/qix/qix.cpp	-o	qix.so
	g++	-shared	-fPIC	game/solarFox/solarFox.cpp	-o	solarFox.so
	gcc	$(CXX)	-c	$(SRC)
	g++	-o	$(NAME)	*.o	-L.

clean	:
	rm	-f	*.o
	rm	-f	*.so
	rm	-f	*~

fclean	:	clean
	rm	-f	$(NAME)

re	:	fclean	all