/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_event2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:22:36 by ehay              #+#    #+#             */
/*   Updated: 2024/04/02 15:13:53 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_non_special(int key, t_game_instance *game_init)
{
	if (key == ESC)
	{
		ft_printf("\nGame ended, you are a noob.\n");
		ft_exit_program(game_init);
	}
	return (0);
}

int	ft_check_keyboard(int key, t_game_instance *game_init)
{
	static int	anim_state_up = 0;
	static int	anim_state_down = 0;
	static int	anim_state_right = 0;
	static int	anim_state_left = 0;

	ft_non_special(key, game_init);
	if (key == W || key == UP)
	{
		anim_state_up = ft_keyboard_up(game_init, anim_state_up);
	}
	else if (key == S || key == DOWN)
	{
		anim_state_down = ft_keyboard_down(game_init, anim_state_down);
	}
	else if (key == A || key == LEFT)
	{
		anim_state_left = ft_keyboard_left(game_init, anim_state_left);
	}
	else if (key == D || key == RIGHT)
	{
		anim_state_right = ft_keyboard_right(game_init, anim_state_right);
	}
	return (0);
}

void	ft_win(t_game_instance *game_init)
{
	game_init->map_init.matrice[game_init->positions_init.player_row]
	[game_init->positions_init.player_col] = EMPTY;
	game_init->game_data.count_movements++;
	ft_printf("\nGg, you have collected all cheese like a big rat.\n");
	ft_exit_program(game_init);
}

int	ft_player_moves(t_game_instance *game_init)
{
	char	*movements;

	movements = ft_itoa(game_init->game_data.count_movements);
	mlx_string_put(game_init->mlx_ptr, game_init->win_ptr,
		20, 16, 0x00FFFFFF, movements);
	free(movements);
	return (0);
}
