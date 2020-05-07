SRC		=	00.5.preliminary.c					\
			00.endianness.c						\
			01.structure_members_offset.c		\
			02.stack_vs_heap_allocation.c 		\
			03.stack_overflow.c 				\
			04.1.stack_manipulation.c			\
			04.2.stack_manipulation.c			\
			05.runtime_stack_allocation.c		\
			06.memory_overlapping.c				\
			07.memory_dumping.c					\
			08.static_variable.c

OBJ		=	$(SRC:.c=.o)
NAMES	=	$(SRC:.c=)

DEBUG	=	-g
WARN	=	-w
CFLAGS	=	-Ilib $(WARN) $(DEBUG)
LFLAGS	=	-Llib -lmem

all:	lib $(OBJ)
	@$(foreach name,$(NAMES),$(CC) -o $(name) $(name).o $(LFLAGS);)

lib:
	@$(MAKE) -C lib

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C lib

fclean:	clean
	$(RM) $(NAMES)
	$(MAKE) fclean -C lib

re: fclean all

.PHONY:	all lib clean fclean