/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:28:24 by ehay              #+#    #+#             */
/*   Updated: 2024/04/08 14:23:33 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_lines(int fd)
{
	int		count;
	char	buffer[BUFFER_SIZE];
	ssize_t	n_read;
	int		i;

	count = 0;
	while (1)
	{
		n_read = read(fd, buffer, BUFFER_SIZE);
		if (n_read < 0)
			return (0);
		if (n_read == 0)
			break ;
		i = 0;
		while (i < n_read)
		{
			if (buffer[i] == '\n')
				count++;
			i++;
		}
	}
	count++;
	return (count);
}

int	ft_check_read(t_game_instance *game_init)
{
	if (game_init->map_init.matrice[0] == NULL
		|| !ft_map_dimensions(game_init) || !ft_is_valid_map(game_init))
	{
		ft_free_map(game_init);
		return (0);
	}
	return (1);
}
