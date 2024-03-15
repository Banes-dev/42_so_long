CC = cc

CFLAGS = -g -Wall -Wextra -Werror

NAME = so_long
FUNC = src/so_long.c src/error.c src/utils/printf.c src/utils/printf_utils.c
OBJS = ${FUNC:.c=.o}

MLX_PATH = ./mlx/
MLX_FLAGS = -lmlx -lmlx_Linux -lX11 -lXext -lm


all: 	${NAME}

${NAME}: ${OBJS}
	make -C $(MLX_PATH) --no-print-directory
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} -L$(MLX_PATH) $(MLX_FLAGS)

clean:	
	rm -f ${OBJS}
	@make clean -C ${MLX_PATH} --no-print-directory

fclean:	clean
	rm -f ${NAME}
	@make clean -C ${MLX_PATH} --no-print-directory

re:	fclean all

.PHONY: all clean fclean re