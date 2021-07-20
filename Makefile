NAME	= push_swap
SRCDIR	= ./
OBJDIR	= ./
SRC		= ${SRCDIR}calc.c\
		  ${SRCDIR}calc2.c\
		  ${SRCDIR}get_index.c\
		  ${SRCDIR}greater_than.c\
		  ${SRCDIR}list_cmd.c\
		  ${SRCDIR}list_funcs.c\
		  ${SRCDIR}main.c\
		  ${SRCDIR}mark_up.c\
		  ${SRCDIR}parser_utils.c\
		  ${SRCDIR}ps_commands.c\
		  ${SRCDIR}utils.c\
		  ${SRCDIR}utils2.c\

OBJ		= ${patsubst ${SRCDIR}%.c, ${OBJDIR}%.o, ${SRC}}
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

${OBJDIR}%.o: ${SRCDIR}%.c
	${CC} ${CFLAGS} -c $< -o push_swap

${NAME}: ${OBJ}
	gcc ${NAME} ${OBJ}

all:  ${NAME}

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all