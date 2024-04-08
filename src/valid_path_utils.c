/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:14:33 by ehay              #+#    #+#             */
/*   Updated: 2024/04/08 14:20:39 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy_matrix(char **dest, char **src, t_game_instance *game_init)
{
	int	row;
	int	col;

	row = 0;
	while (row < game_init->map_init.resolutions.settings_map_height)
	{
		col = 0;
		while (col < game_init->map_init.resolutions.settings_map_width)
		{
			dest[row][col] = src[row][col];
			col++;
		}
		row++;
	}
}
