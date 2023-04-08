##
## EPITECH PROJECT, 2023
## Arcade
## File description:
## Makefile
##

SRC_SDL		=	SDL2/

SRC_NCURSE	=	NCurse/

SRC_SFML	=	sfml/

all:
	$(MAKE) -C $(SRC_SDL)
	$(MAKE) -C $(SRC_SFML)
	# $(MAKE) -C $(SRC_NCURSE)

clean:
	$(MAKE) clean -C $(SRC_SDL)
	$(MAKE) clean -C $(SRC_SFML)
	$(MAKE) clean -C $(SRC_NCURSE)

fclean: clean
	$(MAKE) fclean -C $(SRC_SDL)
	$(MAKE) fclean -C $(SRC_SFML)
	$(MAKE) fclean -C $(SRC_NCURSE)

re: fclean all

.PHONY:    all clean fclean re