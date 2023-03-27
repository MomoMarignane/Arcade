##
##	EPITECH PROJECT, 2022
## Arcade
## File description:
## Makefile
##

SRC	=	arcade.cpp	\
		utils/myStrCmp.cpp	\

OBJ	=	$(SRC:.c=.o)

CXX	=	-Wall	-Wextra	-std=c++20

NAME	=	arcade

all	:	games	graphicals	core

games:
	g++	$(CXX)	-shared	-fPIC	Game/snake/snake.cpp	-o	lib/snake.so
	g++	$(CXX)	-shared	-fPIC	Game/solarFox/solarFox.cpp	-o	lib/solarFox.so

graphicals:
	g++	$(CXX)	-lncurses	-shared	-fPIC	Graphical/ncurses/ncurses.cpp	-o	lib/ncurses.so
	g++	$(CXX)	-lsfml-graphics	-lsfml-window	-lsfml-system	-shared	-fPIC	Graphical/sfml/sfml.cpp	-o	lib/sfml.so
# g++	$(CXX)	-lSDL2_image	-lSDL2_ttf	-lSDL2	-lSDL2main	-shared	-fPIC	Graphical/SDL2/sdl2.cpp	-o	lib/sdl2.so

core: $(NAME) $(SRC)
	g++	$(CXX)	$(SRC)	-ldl	-o	$(NAME)

clean	:
	rm	-f	*.o
	rm	-f	*.so
	rm	-f	lib/*.so
	rm	-f	*~

fclean	:	clean
	rm	-f	$(NAME)

re	:	fclean	all