##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

CC	=	gcc

RM	=	rm -f

MK	=	mkdir -p

SRC	=	main.c			\
		read_functions.c	\
		fill_tab.c		\
		check_table.c		\
		border_and_other.c

OBJDIR 	=	obj/

SRCDIR 	=	src/

MAKELIB	=	make -C lib/my/

OBJ	=	$(addprefix $(OBJDIR), $(SRC:.c=.o))

NAME	=	bsq

CFLAG	+=	-W
CFLAG	+=	-Wall
CFLAG	+=	-I./include
CFLAG	+=	-L./lib
##CFLAG	+=	-g

LIB	=	-lmy

$(OBJDIR)%.o:	$(SRCDIR)%.c
	$(MK) $(OBJDIR)
	$(CC) $(CFLAG) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKELIB)
	$(CC) $(CFLAG) -o $(NAME) $(OBJ) $(LIB)
clean:
	$(RM) -r $(OBJDIR)
	$(MAKELIB) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKELIB) fclean

re:	fclean all

.PHONY: clean fclean re all
