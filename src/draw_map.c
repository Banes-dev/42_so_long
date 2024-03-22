/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:29:34 by ehay              #+#    #+#             */
/*   Updated: 2024/03/22 15:32:50 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set(t_game_instance *game_init, void *img, int wid, int hgt)
{
	mlx_put_image_to_window(game_init->mlx_ptr, game_init->win_ptr,
		img, wid * 32, hgt * 32);
}

void	ft_map_continues(t_game_instance *game_init, int column, int row)
{
	if (game_init->map_init.matrice[row][column] == EXIT
		&& game_init->game_data.count_collectible == 0)
		ft_set(game_init, game_init->game_objs.exit_open, column, row);
	if (game_init->map_init.matrice[row][column] == EXIT
		&& game_init->game_data.count_collectible != 0)
		ft_set(game_init, game_init->game_objs.exit_close, column, row);
	return ;
}

int	ft_map_draw(t_game_instance *game_init)
{
	int	row;
	int	column;

	row = -1;
	while (game_init->map_init.matrice[++row])
	{
		column = 0;
		while (game_init->map_init.matrice[row][column])
		{
			if (game_init->map_init.matrice[row][column] == WALL)
				ft_set(game_init, game_init->game_objs.wall, column, row);
			if (game_init->map_init.matrice[row][column] == EMPTY)
				ft_set(game_init, game_init->game_objs.floor, column, row);
			if (game_init->map_init.matrice[row][column] == PLAYER)
				ft_set(game_init, game_init->game_objs.player, column, row);
			ft_map_continues(game_init, column, row);
			if (game_init->map_init.matrice[row][column] == COLLECTIBLE)
				ft_set(game_init, game_init->game_objs.collectible,
					column, row);
			column++;
		}
	}
	return (0);
}
