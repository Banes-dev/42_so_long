CC = cc

CFLAGS = -g -Wall -Wextra -Werror

NAME = so_long
FUNC = so_long.c utils/printf.c utils/printf_utils.c
OBJS = ${FUNC:.c=.o}

# MLX_PATH = minilibx-linux/
# FLAGS_MLX = -lft -lmlx -lmlx_Linux -lX11 -lXext -lm
MLX = minilibx-linux/ -lmlx -lX11 -lXext -lm

all: 	${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${MLX}

clean:	
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re