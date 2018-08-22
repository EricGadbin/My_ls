##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC  	=	my_strcmp.c\
		my_putstrmajs.c\
		my_printf.c\
		my_putchar.c\
		my_putnb_b.c\
		my_put_nbr.c\
		my_put_nbr_short.c\
		my_put_nbr_uns.c\
		my_putptr.c\
		my_putstr.c\
		my_strlen.c\

OBJ	=	$(SRC:.c=.o)

CFLAGS  =	-W -Wall -Wextra -Werror -pedantic -I../include

NAME	= 	my

all: $(NAME)

$(NAME):	$(OBJ)
	ar rc libmy.a $(OBJ)
clean:
	rm -f *.o
	rm -f *~

fclean: clean
	rm -f libmy.a

re:	fclean all
