/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:13:08 by ehay              #+#    #+#             */
/*   Updated: 2024/03/15 15:43:57 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_struct_init(t_game_instance *game_init)
{
	t_game_objs	*objects;

	*game_init = (t_game_instance){0};
	game_init->map_init.matrice = NULL;
	game_init->mlx_ptr = NULL;
	game_init->win_ptr = NULL;
	game_init->resolutions_init.settings_name_map = NULL;
	game_init->resolutions_init.settings_name_window = NULL;
	objects = malloc(sizeof(t_game_objs));
	if (objects == NULL)
		ft_error(666);
	game_init->game_objs = *objects;
	free (objects);
	return ;
}

int	main(int argc, char **argv)
{
	t_game_instance	game_init;

	if (argc == 2 && argv[1] != NULL)
	{
		ft_struct_init(&game_init);
        ft_printf("ouiiiiiiiii\n");
	}
	else
		ft_error(1);
	return (0);
}