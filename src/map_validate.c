/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:59:51 by ehay              #+#    #+#             */
/*   Updated: 2024/04/08 14:23:21 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_wall(t_game_instance *game_init)
{
	int		i;
	int		j;

	i = 0;
	while (i < game_init->map_init.rows_matrice)
	{
		j = 0;
		while (j < game_init->map_init.cols_matrice)
		{
			if (i == 0 || j == 0 || i == game_init->map_init.rows_matrice
				- 1 || j == game_init->map_init.cols_matrice - 1)
			{
				if (game_init->map_init.matrice[i][j] != WALL)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_have_requires(t_game_instance *game_init)
{
	if (!(game_init->game_data.count_player == 1
			&& game_init->game_data.count_exit == 1
			&& game_init->game_data.count_collectible >= 1))
		return (0);
	return (1);
}

void	ft_count_second(t_game_instance *game_init, int row, int colum)
{
	if (game_init->map_init.matrice[row][colum] == PLAYER)
		game_init->game_data.count_player++;
	else if (game_init->map_init.matrice[row][colum] == EXIT)
		game_init->game_data.count_exit++;
	else if (game_init->map_init.matrice[row][colum] == COLLECTIBLE)
		game_init->game_data.count_collectible++;
	else if (game_init->map_init.matrice[row][colum] == WALL)
		game_init->game_data.count_wall++;
	else if (game_init->map_init.matrice[row][colum] == EMPTY)
		game_init->game_data.count_empty++;
}

int	ft_count_map_objects(t_game_instance *game_init)
{
	int	row;
	int	column;

	row = -1;
	while (game_init->map_init.matrice[++row])
	{
		column = 0;
		while (game_init->map_init.matrice[row][column])
		{
			if (game_init->map_init.matrice[row][column] == PLAYER
				|| game_init->map_init.matrice[row][column] == EXIT
				|| game_init->map_init.matrice[row][column] == COLLECTIBLE
				|| game_init->map_init.matrice[row][column] == WALL
				|| game_init->map_init.matrice[row][column] == EMPTY)
				ft_count_second(game_init, row, column);
			else if (game_init->map_init.matrice[row][column] != '\n')
				return (0);
			column++;
		}
	}
	return (ft_have_requires(game_init));
}

int	ft_is_valid_map(t_game_instance *game_init)
{
	if (!(ft_count_map_objects(game_init)))
		return (0);
	if (!(ft_is_map_shape_valid(game_init)))
		return (0);
	if (!(ft_is_wall(game_init)))
		return (0);
	return (1);
}
