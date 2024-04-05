CC = cc

CFLAGS = -g -Wall -Wextra -Werror

# Normal
NAME = so_long
FUNC = src/draw_map.c src/error.c src/exit.c src/free.c src/game_event.c src/game_event2.c  src/game_init.c \
			src/map_dimension.c src/map_utils.c src/map_validate.c src/map.c src/so_long.c  \
			src/utils/printf.c src/utils/printf_utils.c src/utils/other_utils.c src/utils/get_next_line.c
OBJS = ${FUNC:.c=.o}

# Bonus
NAME_BONUS = so_long_bonus
FUNC_BONUS = src_bonus/draw_map.c src_bonus/error.c src_bonus/exit.c src_bonus/free.c src_bonus/game_event.c src_bonus/game_event2.c \
			src_bonus/game_init.c src_bonus/map_dimension.c src_bonus/map_utils.c src_bonus/map_validate.c src_bonus/map_validate_utils.c \
			src_bonus/map.c src_bonus/so_long_bonus.c src_bonus/anim.c src_bonus/keyboard_action.c src_bonus/valid_path.c \
			src_bonus/utils/printf.c src_bonus/utils/printf_utils.c src_bonus/utils/other_utils.c src_bonus/utils/get_next_line.c src_bonus/utils/itoa.c
OBJS_BONUS = ${FUNC_BONUS:.c=.o}

# Mlx
MLX_PATH = ./mlx/
MLX_FLAGS = -lmlx -lmlx_Linux -lX11 -lXext -lm


# Compil
all: 	${NAME}

${NAME}: ${OBJS}
	make -C $(MLX_PATH) --no-print-directory
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} -L$(MLX_PATH) $(MLX_FLAGS)

bonus: 	${NAME_BONUS}

${NAME_BONUS}: ${OBJS_BONUS}
	make -C $(MLX_PATH) --no-print-directory
	${CC} ${CFLAGS} ${OBJS_BONUS} -o ${NAME_BONUS} -L$(MLX_PATH) $(MLX_FLAGS)

clean:	
	rm -f ${OBJS}
	rm -f ${OBJS_BONUS}
	@make clean -C ${MLX_PATH} --no-print-directory

fclean:	clean
	rm -f ${NAME}
	rm -f ${NAME_BONUS}
	@make clean -C ${MLX_PATH} --no-print-directory

re:	fclean all

.PHONY: all clean fclean re bonus