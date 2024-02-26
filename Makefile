CC = cc

CFLAGS = -g -Wall -Wextra -Werror

# Base
NAME = so_long

FUNC = so_long.c utils/printf.c utils/printf_utils.c

OBJS = ${FUNC:.c=.o}


all: 	${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:	
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re