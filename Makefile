SRCS	= ./push_swap.c
OBJS	= $(SRCS:.c=.o)
CC		= gcc -Wall -Werror -Wextra

all:	$(NAME)

$(NAME):	$(OBJS)
			${CC} ${OBJS} -o push_swap
			echo "Done"
clean:
			rm -f ${OBJS}