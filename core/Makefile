##
## EPITECH PROJECT, 2023
## SFML
## File description:
## Makefile
##

NAME		=	arcade

SRC       	=  	source/Core.cpp	\
				source/DynamicLoader.cpp

OBJ         =	$(SRC:.cpp=.o)

CC          =	g++

CPPFLAGS	=	-Iinclude/ -I../Module\ Interface/

CXXFLAGS      =   -W -Wall -Wextra -fPIC

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) $(CXXFLAGS)
	cp $(NAME) ../

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) ../$(NAME)

re: fclean all

.PHONY:    all clean fclean re