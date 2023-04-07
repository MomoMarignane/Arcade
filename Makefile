##
##	EPITECH PROJECT, 2022
## Arcade
## File description:
## Makefile
##

SRC	=	arcade.cpp	\
		utils/myStrCmp.cpp	\
		board/board.cpp	\

OBJ	=	$(SRC:.c=.o)

CXX_FLAGS	=	-Wall	-Wextra	-std=c++20

NAME	=	arcade

all	:	games	graphicals	core

games:
	g++	$(CXX_FLAGS)	-shared	-fPIC	Game/snake/snake.cpp	-o	lib/arcade_snake.so
	g++	$(CXX_FLAGS)	-shared	-fPIC	Game/solarFox/solarFox.cpp	-o	lib/arcade_solarfox.so

graphicals:
	g++	$(CXX_FLAGS)	-shared	-fPIC	Graphical/ncurses/ncurses.cpp	-o	lib/arcade_ncurses.so	-lncurses
	g++	$(CXX_FLAGS)	-shared	-fPIC	Graphical/sfml/sfml.cpp	-o	lib/arcade_sfml.so	-lsfml-graphics	-lsfml-window	-lsfml-system
# g++	$(CXX_FLAGS)	-shared	-fPIC	Graphical/SDL2/sdl2.cpp	-o	lib/arcade_sdl2.so	-lSDL2_ttf	-lSDL2	-lSDL2main	-lSDL2_image

core: $(SRC)
	g++	$(CXX_FLAGS)	$(SRC)	-ldl	-o	$(NAME)

clean	:
	rm	-f	*.o
	rm	-f	*.so
	rm	-f	lib/*.so
	rm	-f	*~

fclean	:	clean
	rm	-f	$(NAME)

re	:	fclean	all