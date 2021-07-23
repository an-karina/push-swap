SRC		= calc.c\
		  calc2.c\
		  get_index.c\
		  greater_than.c\
		  list_cmd.c\
		  list_funcs.c\
		  main.c\
		  mark_up.c\
		  parser_utils.c\
		  ps_commands.c\
		  utils.c\
		  utils2.c\

OBJS		= $(SRC:.c=.o)

CC			= gcc -g -O2
RM			= rm -f
NAME		= push_swap

all:		$(NAME)

$(NAME):	 $(OBJS)
				gcc -g ${OBJS} -o push_swap
				@echo "Done"

clean:
				$(RM) $(OBJS)

fclean:
				$(RM) $(OBJS) $(NAME)

re:			fclean $(NAME)

.PHONY:			all clean fclean re