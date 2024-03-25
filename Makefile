CC = cc

CFLAGS = -g -Wall -Wextra -Werror

NAME = so_long
FUNC = src/draw_map.c src/error.c src/exit.c src/free.c src/game_event.c src/game_event2.c  src/game_init.c \
			src/map_dimension.c src/map_utils.c src/map_validate.c src/map.c src/so_long.c  \
			src/utils/printf.c src/utils/printf_utils.c src/utils/other_utils.c src/utils/get_next_line.c
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