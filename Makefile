CC = cc

CFLAGS = -g -Wall -Wextra -Werror

NAME = so_long
FUNC = so_long.c utils/printf.c utils/printf_utils.c
OBJS = ${FUNC:.c=.o}

MLX_PATH = ./mlx/
LFLAGS = -lmlx -lmlx_Linux -lX11 -lXext -lm


all: 	${NAME}

${NAME}: ${OBJS}
	make -C $(MLX_PATH) --no-print-directory
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} -L$(MLX_PATH) $(LFLAGS)

clean:	
	rm -f ${OBJS}
	@make clean -C ${MLX_PATH} --no-print-directory

fclean:	clean
	rm -f ${NAME}
	@make clean -C ${MLX_PATH} --no-print-directory

re:	fclean all

.PHONY: all clean fclean re