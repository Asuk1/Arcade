##
## EPITECH PROJECT, 2023
## SFML
## File description:
## Makefile
##

SRC_CORE		=	core/

SRC_GRAPHICS	=	GraphicExemple/

SRC_GAME		=	Game/

all:
	$(MAKE) -C $(SRC_CORE)
	$(MAKE) -C $(SRC_GRAPHICS)

graphicals:
	$(MAKE) -C $(SRC_GRAPHICS)

core:
	$(MAKE) -C $(SRC_CORE)

games:
	$(MAKE) -C $(SRC_GAME)

clean:
	$(MAKE) clean -C $(SRC_CORE)
	$(MAKE) clean -C $(SRC_GRAPHICS)

fclean: clean
	$(MAKE) fclean -C $(SRC_CORE)
	$(MAKE) fclean -C $(SRC_GRAPHICS)

re: fclean all

.PHONY:    all clean fclean re core graphicals games