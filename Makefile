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
	g++	$(CXX)	-shared	-fPIC	Game/snake/snake.cpp	-o	snake.so
	g++	$(CXX)	-shared	-fPIC	Game/nibbler/nibbler.cpp	-o	nibbler.so
	g++	$(CXX)	-shared	-fPIC	Game/solarFox/solarFox.cpp	-o	solarFox.so
	gcc	$(CXX)	-c	$(SRC)
	g++	-o	$(NAME)	*.o	-L.
	mv	*.so	lib

clean	:
	rm	-f	*.o
	rm	-f	*.so
	rm	-f	lib/*.so
	rm	-f	*~

fclean	:	clean
	rm	-f	$(NAME)

re	:	fclean	all