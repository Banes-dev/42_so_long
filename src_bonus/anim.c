/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:38:04 by ehay              #+#    #+#             */
/*   Updated: 2024/04/05 13:26:17 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_anim_collectable(t_game_instance *game_init)
{
	if (game_init->game_data.anim_collectible >= 3)
		game_init->game_data.anim_collectible = 0;
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.collectible);
	if (game_init->game_data.anim_collectible == 0)
		game_init->game_objs.collectible
			= mlx_xpm_file_to_image(game_init->mlx_ptr,
				"ressources/img/wall/cheese_anim1.xpm",
				&game_init->game_objs.img_width,
				&game_init->game_objs.img_height);
	else if (game_init->game_data.anim_collectible == 1)
		game_init->game_objs.collectible
			= mlx_xpm_file_to_image(game_init->mlx_ptr,
				"ressources/img/wall/cheese_anim2.xpm",
				&game_init->game_objs.img_width,
				&game_init->game_objs.img_height);
	else if (game_init->game_data.anim_collectible == 2)
		game_init->game_objs.collectible
			= mlx_xpm_file_to_image(game_init->mlx_ptr,
				"ressources/img/wall/cheese_anim3.xpm",
				&game_init->game_objs.img_width,
				&game_init->game_objs.img_height);
	game_init->game_data.anim_collectible++;
	return (0);
}
