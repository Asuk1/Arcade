##debu
## EPITECH PROJECT, 2022
## NCurse
## File description:
## Makefile
##

NAME		=	arcade_NCurse.so

SRC       	=  	sources/NCurses.cpp			 		\

OBJ         =	$(SRC:.cpp=.o)

CC          =	g++

CPPFLAGS	=	-Iinclude/

CXXFLAGS      =   -W -Wall -Wextra -fPIC -std=c++17 -fno-gnu-unique

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -shared -o $(NAME) $(OBJ)
	cp $(NAME) ../../../lib/

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)
		$(RM) ../../../lib/$(NAME)

re: fclean all

.PHONY:    all clean fclean re debug