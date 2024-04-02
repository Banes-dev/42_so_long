/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:03:51 by ehay              #+#    #+#             */
/*   Updated: 2024/04/02 14:03:46 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "stdio.h"           // printf and other
# include "unistd.h"
# include "stdlib.h"          // malloc & free
# include "stdarg.h"          // fonction va_
# include "stddef.h"          // size_t
# include "limits.h"          // INT_MIN et INT_MAX
# include "fcntl.h" 		  // Read
# include "string.h" 		  // fonction string
# include "../mlx/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define WINDOW_WIDTH 960
# define WINDOW_HEIGHT 540

# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define WALL '1'
# define EMPTY '0'
# define ENNEMIES 'S'

# define ESC 65307
# define W 119
# define UP 65362
# define A 97
# define LEFT 65361
# define S 115
# define DOWN 65364
# define D 100
# define RIGHT 65363

// OBJECTS : IMAGES
typedef struct s_game_objs
{
	void	*player;
	void	*player_left;
	void	*player_right;
	void	*player_down;
	void	*player_up;
	void	*player_left2;
	void	*player_right2;
	void	*player_down2;
	void	*player_up2;
	void	*collectible;
	void	*ennemies;
	void	*exit_open;
	void	*exit_close;
	void	*wall;
	void	*floor;
	int		img_width;
	int		img_height;
}	t_game_objs;

// POSITIONS OF PLAYER AND EXIT
typedef struct s_game_positions
{
	int	player_row;
	int	player_col;
	int	exit_row;
	int	exit_col;
}	t_game_positions;

// GAME DATA OF THE OBJECTS INSIDE THE MATRICE (INTERNAL)
typedef struct s_game_data
{
	int	count_player;
	int	count_exit;
	int	count_collectible;
	int	count_ennemies;
	int	count_wall;
	int	count_empty;
	int	count_movements;
	int	endgame;
	int	anim_collectible;
}	t_game_data;

// GAME RESOLUTIONS 
typedef struct s_game_resolutions
{
	int		settings_map_width;
	int		settings_map_height;
	char	*settings_name_window;
	char	*settings_name_map;
}	t_game_resolutions;

// GAME DATA OF MATRICE (EXTERN)
typedef struct s_map_data
{
	int					first_read_matrice;
	int					cols_matrice;
	int					rows_matrice;
	int					size_matrice;
	char				**matrice;
	t_game_resolutions	resolutions;
	t_game_positions	positions;
}	t_map_data;

// MAIN GAME CONTROLLER
typedef struct s_game_instance
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					argc_tmp;
	char				**argv_tmp;
	t_map_data			map_init;
	t_game_positions	positions_init;
	t_game_data			game_data;
	t_game_resolutions	resolutions_init;
	t_game_objs			game_objs;
}	t_game_instance;

///////////
////// GAME
int		main(int argc, char **argv);
int		ft_anim_collectable(t_game_instance *game_init);
// Map
int		ft_open_map(char *map, t_game_instance *game_init);
int		ft_count_lines(int fd);
int		ft_check_read(t_game_instance *game_init);
int		ft_map_dimensions(t_game_instance *game_init);
int		ft_is_valid_map(t_game_instance *game_init);

// Window
void	ft_initialize_game(t_game_instance *game_init);
void	ft_gameplay_start(t_game_instance *game_init);
int		ft_check_keyboard(int key, t_game_instance *game_init);
void	ft_win(t_game_instance *game_init);
int		ft_events_pressed(t_game_instance *game_init, int column, int row);
int		ft_map_draw(t_game_instance *game_init);

// Keyboard
int		keyboard_up(t_game_instance *game_init, int anim);
int		keyboard_down(t_game_instance *game_init, int anim);
int		keyboard_left(t_game_instance *game_init, int anim);
int		keyboard_right(t_game_instance *game_init, int anim);

// Exit
int		ft_exit_program(t_game_instance *game_init);

// Error
void	ft_error(int num_error);

// Free
void	ft_free_map(t_game_instance *game_init);
void	ft_free_img(t_game_instance *game_init);

////////////
////// UTILS
// ft_printf
int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_putpointer(void *adress);
int		ft_puthexalower(long double number);
int		ft_puthexaupper(long double number);

// Get next line
char	*get_next_line(int fd);

// Other
size_t	ft_strlen(const char *s);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strchr(const char *str, int ch);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_itoa(int n);

#endif