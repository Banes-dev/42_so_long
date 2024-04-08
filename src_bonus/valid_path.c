/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:36:12 by ehay              #+#    #+#             */
/*   Updated: 2024/04/08 14:16:13 by ehay             ###   ########.fr       */
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
		row++;
	}
	if (game_init->path_setting.start_row == -1)
		return (0);
	return (1);
}

int	pathing_map(t_game_instance *game_init, char **matrix_copy,
	int row, int col)
{
	int	res1;
	int	res2;
	int	res3;
	int	res4;
	int	result;

	res1 = is_valid_path(game_init, matrix_copy, row - 1, col);
	res2 = is_valid_path(game_init, matrix_copy, row + 1, col);
	res3 = is_valid_path(game_init, matrix_copy, row, col - 1);
	res4 = is_valid_path(game_init, matrix_copy, row, col + 1);
	result = (res1 || res2 || res3 || res4);
	return (result);
}

int	is_valid_path(t_game_instance *game_init, char **matrix_copy,
	int row, int col)
{
	int	result;

	if (row < 0 || row >= game_init->map_init.resolutions.settings_map_height
		|| col < 0 || col >= game_init->map_init.resolutions.settings_map_width
		|| matrix_copy[row][col] == WALL
		|| matrix_copy[row][col] == '-'
		|| matrix_copy[row][col] == ENNEMIES)
		return (0);
	if (matrix_copy[row][col] == 'E')
		game_init->path_setting.exit_found++;
	else if (matrix_copy[row][col] == 'C')
		game_init->path_setting.collec_found++;
	matrix_copy[row][col] = '-';
	result = pathing_map(game_init, matrix_copy, row, col);
	if (game_init->path_setting.exit_found == game_init->game_data.count_exit
		&& game_init->path_setting.collec_found
		== game_init->game_data.count_collectible)
		return (1);
	return (result);
}

char	**allocate_matrix_copy(t_game_instance *game_init)
{
	char	**matrix_copy;
	int		row;

	matrix_copy = malloc((
				game_init->map_init.resolutions.settings_map_height + 1)
			* sizeof(char *));
	if (!matrix_copy)
		return (NULL);
	row = 0;
	while (row < game_init->map_init.resolutions.settings_map_height)
	{
		matrix_copy[row] = malloc((
					game_init->map_init.resolutions.settings_map_width + 1)
				* sizeof(char));
		if (!matrix_copy[row])
		{
			while (--row >= 0)
				free(matrix_copy[row]);
			free(matrix_copy);
			matrix_copy = NULL;
			return (NULL);
		}
		row++;
	}
	return (matrix_copy);
}

int	ft_valid_path(t_game_instance *game_init)
{
	char	**matrix_copy;

	if (!init_player_coords(game_init, 0, 0))
		return (0);
	matrix_copy = allocate_matrix_copy(game_init);
	if (!matrix_copy)
		return (0);
	copy_matrix(matrix_copy, game_init->map_init.matrice, game_init);
	if (!is_valid_path(game_init, matrix_copy,
			game_init->path_setting.start_row,
			game_init->path_setting.start_col))
	{
		ft_free_matrix(matrix_copy);
		return (0);
	}
	ft_free_matrix(matrix_copy);
	return (1);
}
