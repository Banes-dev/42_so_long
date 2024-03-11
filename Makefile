CC = cc

CFLAGS = -g -Wall -Wextra -Werror

NAME = so_long
FUNC = so_long.c utils/printf.c utils/printf_utils.c
OBJS = ${FUNC:.c=.o}

MLX = ./mlx_linux/
# MLX_FLAGS = -lft -lmlx -lmlx_Linux -lX11 -lXext -lm
MLX_TEST = -I/usr/include -Imlx_linux -O3

all: 	${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${MLX_TEST} -o ${NAME}

clean:	
	rm -f ${OBJS}
	@make clean -C ${MLX} --no-print-directory

fclean:	clean
	rm -f ${NAME}
	@make clean -C ${MLX} --no-print-directory

re:	fclean all

.PHONY: all clean fclean re