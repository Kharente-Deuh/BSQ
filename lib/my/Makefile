##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC	=	gcc

AR	=	ar rc

RM 	=	rm -f

MK	=	mkdir -p

CP	=	cp

CPLIB	=	../libmy.a

CPDIR	=	../../include/my.h

MY	=	my.h

SRC	=	my_strlen.c

OBJDIR	=	obj/

SRCDIR = 	src/

OBJ	=	$(addprefix $(OBJDIR), $(SRC:.c=.o))

CFLAG	=	-I./

NAME	=	libmy.a

$(OBJDIR)%.o:	$(SRCDIR)%.c
	$(MK) $(OBJDIR)
	$(CC) $(CFLAG) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJ)
	$(AR) $(NAME) $(OBJ)
	$(CP) $(MY) $(CPDIR)
	$(CP) $(NAME) $(CPLIB)
clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(CPLIB)

re:	fclean all

.PHONY: clean fclean re all
