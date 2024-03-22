/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:01:13 by ehay              #+#    #+#             */
/*   Updated: 2024/03/22 15:47:07 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	ft_img_init(t_game_instance *game_init)
{
	ft_check_img(game_init, &game_init->game_objs.player_up,
		"rscs/textures/Player/walkUP_00.xpm");
	ft_check_img(game_init, &game_init->game_objs.player_down,
		"rscs/textures/Player/walkDown_00.xpm");
	ft_check_img(game_init, &game_init->game_objs.player_right,
		"rscs/textures/Player/walkRight_00.xpm");
	ft_check_img(game_init, &game_init->game_objs.player_left,
		"rscs/textures/Player/walkLeft_00.xpm");
	ft_check_img(game_init, &game_init->game_objs.collectible,
		"rscs/textures/Collectibles/star_00.xpm");
	ft_check_img(game_init, &game_init->game_objs.floor,
		"ressources/img/wall/parquet.xpm"); // fait
	ft_check_img(game_init, &game_init->game_objs.exit_open,
		"rscs/textures/Exit/exit_open_01.xpm");
	ft_check_img(game_init, &game_init->game_objs.exit_close,
		"rscs/textures/Exit/exit_close_01.xpm");
	ft_check_img(game_init, &game_init->game_objs.wall,
		"rscs/textures/Tiles/blockSimple.xpm");
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
			* 32, "The Rat.");
	if (game_init->win_ptr == NULL)
		ft_error(89);
}

