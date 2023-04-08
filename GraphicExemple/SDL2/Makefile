##
## EPITECH PROJECT, 2023
## SDL
## File description:
## Makefile
##

NAME		=	arcade_sdl2.so

SRC       	=  	source/createSDL2.cpp	\
				source/sdl2Audio.cpp	\
				source/sdl2Display.cpp	\
				source/sdl2Text.cpp		\
				source/sdl2Sprite.cpp

OBJ         =	$(SRC:.cpp=.o)

CC          =	g++

CPPFLAGS	=	-Iinclude/ -I../../Module\ Interface/

CXXFLAGS      =   -W -Wall -Wextra -fPIC

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -shared -o $(NAME) $(OBJ) -lSDL2 -lSDL2_ttf -lSDL2_mixer -lSDL2_image
	cp $(NAME) ../../lib/

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)
		$(RM) ../../lib/$(NAME)

re: fclean all

.PHONY:    all clean fclean re