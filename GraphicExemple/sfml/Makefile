##
## EPITECH PROJECT, 2023
## SFML
## File description:
## Makefile
##

NAME		=	arcade_sfml.so

SRC       	=  	sources/sfml.cpp	\
				sources/SfmlAudio.cpp	\
				sources/SfmlDisplay.cpp	\
				sources/SfmlSprite.cpp	\
				sources/SfmlText.cpp

OBJ         =	$(SRC:.cpp=.o)

CC          =	g++

CPPFLAGS	=	-Iinclude/ -I../../Module\ Interface/

CXXFLAGS      =   -W -Wall -Wextra -fPIC

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -shared -o $(NAME) $(OBJ) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
	cp $(NAME) ../../lib/

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)
		$(RM) ../../lib/$(NAME)

re: fclean all

.PHONY:    all clean fclean re