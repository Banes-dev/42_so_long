/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:10:17 by ehay              #+#    #+#             */
/*   Updated: 2024/03/22 15:14:45 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_cleanup(t_game_instance *game_init)
{
	if (game_init->resolutions_init.settings_name_window != NULL)
	{
		free(game_init->resolutions_init.settings_name_window);
		game_init->resolutions_init.settings_name_window = NULL;
	}
	if (game_init->resolutions_init.settings_name_map != NULL)
	{
		free(game_init->resolutions_init.settings_name_map);
		game_init->resolutions_init.settings_name_map = NULL;
	}
}

void	ft_reset_game(t_game_instance *game_init)
{
	ft_printf("\nGame reset, you are a noob.\n");
	ft_free_img(game_init);
	ft_free_map(game_init);
	free(game_init->resolutions_init.settings_name_window);
	free(game_init->resolutions_init.settings_name_map);
	mlx_destroy_window(game_init->mlx_ptr, game_init->win_ptr);
	mlx_destroy_display(game_init->mlx_ptr);
	free(game_init->mlx_ptr);
	main(game_init->argc_tmp, game_init->argv_tmp);
}

int	ft_exit_program(t_game_instance *game_init)
{
	ft_printf("Quit the game.\n");
	ft_free_img(game_init);
	ft_free_map(game_init);
	ft_cleanup(game_init);
	mlx_destroy_window(game_init->mlx_ptr, game_init->win_ptr);
	mlx_destroy_display(game_init->mlx_ptr);
	free(game_init->mlx_ptr);
	exit(0);
	return (0);
}
