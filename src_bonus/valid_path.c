/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:36:12 by ehay              #+#    #+#             */
/*   Updated: 2024/04/05 15:59:21 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	init_player_coords(t_game_instance *game_init, int row, int col)
{
	while (row < game_init->map_init.resolutions.settings_map_height)
	{
		col = 0;
		while (col < game_init->map_init.resolutions.settings_map_width)
		{
			if (game_init->map_init.matrice[row][col] == 'P')
			{
				game_init->path_setting.start_row = row;
				game_init->path_setting.start_col = col;
				return (1);
			}
			col++;
		}
		// if (game_init->path_setting.start_row != -1)
		// 	break ;
		row++;
	}
	if (game_init->path_setting.start_row == -1)
		return (0);
	return (1);
}

int	pathing_map(t_game_instance *game_init, int row, int col)
{
	int	res1;
	int	res2;
	int	res3;
	int	res4;
	int	result;

	res1 = is_valid_path(game_init, row - 1, col);
	res2 = is_valid_path(game_init, row + 1, col);
	res3 = is_valid_path(game_init, row, col - 1);
	res4 = is_valid_path(game_init, row, col + 1);
	result = (res1 || res2 || res3 || res4);
	return (result);
}

int	is_valid_path(t_game_instance *game_init, int row, int col)
{
	int	result;

	if (row < 0 || row >= game_init->map_init.resolutions.settings_map_height || col < 0 || col >= game_init->map_init.resolutions.settings_map_width
		|| game_init->map_init.matrice[row][col] == WALL
		|| game_init->map_init.matrice[row][col] == '-'
		|| game_init->map_init.matrice[row][col] == ENNEMIES)
		return (0);
	if (game_init->map_init.matrice[row][col] == 'E')
		game_init->path_setting.exit_found++;
	else if (game_init->map_init.matrice[row][col] == 'C')
		game_init->path_setting.collec_found++;
	game_init->map_init.matrice[row][col] = '-';
	ft_printf("test1\n");
	result = pathing_map(game_init, row, col);
	ft_printf("test2\n");
	if (game_init->path_setting.exit_found == game_init->game_data.count_exit && game_init->path_setting.collec_found == game_init->game_data.count_collectible)
		return (1);
	return (result);
}

int	ft_valid_path(t_game_instance *game_init)
{
	if (!init_player_coords(game_init, 0, 0))
		return (0);
	ft_printf("%i, %i\n", game_init->path_setting.start_row, game_init->path_setting.start_col);
	if (!is_valid_path(game_init, game_init->path_setting.start_row, game_init->path_setting.start_col))
		return (0);
	return (1);
}
