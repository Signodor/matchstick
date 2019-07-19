##
## EPITECH PROJECT, 2018
## CPE_pushswap_2018
## File description:
## Makefile
##

NAME	=	matchstick
SRC	=	$(wildcard *.c)
OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Iinclude/ -g3

all:	$(NAME)

$(NAME):	$(OBJ)
	@gcc -o $(NAME) $(OBJ)

clean:
	@find . -name \*.o -type f -delete

fclean:	clean
	@rm -f $(NAME)

re:	fclean	$(NAME)