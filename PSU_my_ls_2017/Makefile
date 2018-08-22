NAME		=	my_ls

CC		=	gcc

RM		=	rm -rf

LIB		=	make -C library/

SRC		=	main.c\
			ls.c\
			sort.c\
			flags_r_d.c\
			flag_l.c\
			flags.c\
			flag_R.c\
			flag_l_params.c\
			my_strcat.c\

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-Wall -Wextra -I./include

all:		$(NAME)

$(NAME):	$(OBJ)
	$(LIB) re
	$(CC) -o $(NAME) $(OBJ) $(LD_FLAGS) -L. library/libmy.a -g3


clean:
	$(RM) $(OBJ)
	$(LIB) clean

fclean:		clean
	$(RM) $(NAME)
	$(LIB) fclean

re:		fclean all
