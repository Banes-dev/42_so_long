/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dimension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:59:08 by ehay              #+#    #+#             */
/*   Updated: 2024/04/08 14:23:40 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_cols_count(t_map_data *map_init)
{
	char	*row;
	int		cols_count;

	row = map_init->matrice[0];
	cols_count = 0;
	while (*row && *row != '\n')
	{
		cols_count++;
		row++;
	}
	return (cols_count);
}

int	get_rows_count(t_game_instance *game_init)
{
	int	row_index;
	int	row_len;

	row_index = 0;
	while (game_init->map_init.matrice[row_index])
	{
		row_len = ft_strlen(game_init->map_init.matrice[row_index])
			- (game_init->map_init.matrice[row_index]
			[ft_strlen(game_init->map_init.matrice[row_index]) - 1] == '\n');
		if (row_len != game_init->map_init.cols_matrice)
		{
			game_init->map_init.rows_matrice = 0;
			return (0);
		}
		game_init->map_init.rows_matrice++;
		row_index++;
	}
	game_init->map_init.size_matrice = game_init->map_init.rows_matrice
		* game_init->map_init.cols_matrice;
	game_init->map_init.resolutions.settings_map_width
		= game_init->map_init.cols_matrice;
	game_init->map_init.resolutions.settings_map_height
		= game_init->map_init.rows_matrice;
	return (1);
}

int	ft_map_dimensions(t_game_instance *game_init)
{
	game_init->map_init.cols_matrice = get_cols_count(&game_init->map_init);
	if (game_init->map_init.cols_matrice == 0)
		return (0);
	return (get_rows_count(game_init));
}
