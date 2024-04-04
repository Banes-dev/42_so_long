/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:01:13 by ehay              #+#    #+#             */
/*   Updated: 2024/04/02 15:16:44 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_img(t_game_instance *game_init, void **image, char *path)
{
	int	width;
	int	height;

	*image = mlx_xpm_file_to_image(game_init->mlx_ptr, path, &width, &height);
	if (*image == NULL)
	{
		ft_error(666);
		ft_exit_program(game_init);
	}
}

void	ft_img_init_player(t_game_instance *game_init)
{
	ft_check_img(game_init, &game_init->game_objs.player_up,
		"ressources/img/player/up/mouse_up_1.xpm");
	ft_check_img(game_init, &game_init->game_objs.player_down,
		"ressources/img/player/down/mouse_down_1.xpm");
	ft_check_img(game_init, &game_init->game_objs.player_right,
		"ressources/img/player/right/mouse_right_1.xpm");
	ft_check_img(game_init, &game_init->game_objs.player_left,
		"ressources/img/player/left/mouse_left_1.xpm");
	ft_check_img(game_init, &game_init->game_objs.player_up2,
		"ressources/img/player/up/mouse_up_2.xpm");
	ft_check_img(game_init, &game_init->game_objs.player_down2,
		"ressources/img/player/down/mouse_down_2.xpm");
	ft_check_img(game_init, &game_init->game_objs.player_right2,
		"ressources/img/player/right/mouse_right_2.xpm");
	ft_check_img(game_init, &game_init->game_objs.player_left2,
		"ressources/img/player/left/mouse_left_2.xpm");
}

void	ft_img_init(t_game_instance *game_init)
{
	ft_img_init_player(game_init);
	ft_check_img(game_init, &game_init->game_objs.collectible,
		"ressources/img/wall/cheese.xpm");
	ft_check_img(game_init, &game_init->game_objs.ennemies,
		"ressources/img/tapette.xpm");
	ft_check_img(game_init, &game_init->game_objs.floor,
		"ressources/img/wall/carrelage.xpm");
	ft_check_img(game_init, &game_init->game_objs.exit_open,
		"ressources/img/door/door_open.xpm");
	ft_check_img(game_init, &game_init->game_objs.exit_close,
		"ressources/img/door/door_close.xpm");
	ft_check_img(game_init, &game_init->game_objs.wall,
		"ressources/img/wall/brique.xpm");
}

void	ft_initialize_game(t_game_instance *game_init)
{
	game_init->mlx_ptr = mlx_init();
	if (game_init->mlx_ptr == NULL)
		ft_error(89);
	game_init->game_data.count_movements = 0;
	ft_img_init(game_init);
	game_init->game_objs.player = game_init->game_objs.player_down;
	game_init->win_ptr = mlx_new_window(game_init->mlx_ptr,
			game_init->map_init.resolutions.settings_map_width
			* 32, game_init->map_init.resolutions.settings_map_height
			* 32, "The Rat Bonus");
	if (game_init->win_ptr == NULL)
		ft_error(89);
}
