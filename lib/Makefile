NAME	=	libmem.a

SRC		=	bytedump.c
OBJ		=	$(SRC:.c=.o)

AR		=	ar rc

CFLAGS	=	

all:	$(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)