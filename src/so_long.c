/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:13:08 by ehay              #+#    #+#             */
/*   Updated: 2024/04/09 12:40:31 by ehay             ###   ########.fr       */
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
		ft_error(666, game_init);
	game_init->game_objs = *objects;
	free(objects);
	return ;
}

int	main(int argc, char **argv)
{
	t_game_instance	game_init;

	if (argc == 2 && argv[1] != NULL)
	{
		ft_struct_init(&game_init);
		game_init.argc_tmp = argc;
		game_init.argv_tmp = argv;
		if (ft_open_map(argv[1], &game_init))
		{
			if (ft_valid_path(&game_init))
			{
				ft_initialize_game(&game_init);
				ft_gameplay_start(&game_init);
				mlx_loop(game_init.mlx_ptr);
			}
			else
				ft_error(3, &game_init);
		}
		else
			ft_error(2, &game_init);
	}
	else
		ft_error(1, &game_init);
	return (0);
}

// mlx_init, init les images, count_mouvement = 0,
// creer la fenetre(mlx_new_window), game_init->game_objs.player = 
// game_init->game_objs.player_down;
