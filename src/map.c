/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:33:14 by ehay              #+#    #+#             */
/*   Updated: 2024/03/18 16:05:06 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		ft_check_map(char *map)
{
	char		*extension;
	char		*file_extension;
	static int	file_count;

	file_count = 0;
	extension = ".ber";
	file_extension = ft_strrchr(map, '.');
	if (map[ft_strlen(map) - 1] == '/')
		return (0);
	else if (!file_extension || !ft_strcmp(file_extension, ""))
		return (0);
	else if (file_extension && !ft_strcmp(file_extension, extension))
	{
		if (file_count >= 1)
			return (0);
		file_count++;
	}
	else
		return (0);
	return (1);
}

int		ft_open_map(char *map, t_game_instance *game_init)
{
	// int		fd;

	(void)game_init;
	if (ft_check_map(map) == 0)
		return (0);
	// fd = open(map, O_RDONLY);
	// if (fd == -1)
	// 	return (0);
	// game_init->map_init.first_read_matrice = ft_read_count_map(map);
	// if (!game_init->map_init.first_read_matrice
	// 	|| game_init->map_init.first_read_matrice < 3)
	// {
	// 	close (fd);
	// 	ft_free_map(game_init);
	// 	return (0);
	// }
	// if (!ft_read_map(fd, game_init))
	// {
	// 	close (fd);
	// 	ft_free_map(game_init);
	// 	return (0);
	// }
	// close (fd);
	return (1);
}
