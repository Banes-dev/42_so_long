/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:55:33 by ehay              #+#    #+#             */
/*   Updated: 2024/04/02 14:56:07 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_keyboard_up(t_game_instance *game_init, int anim)
{
	if (anim == 0)
	{
		game_init->game_objs.player = game_init->game_objs.player_up;
		anim = 1;
	}
	else if (anim == 1)
	{
		game_init->game_objs.player = game_init->game_objs.player_up2;
		anim = 0;
	}
	ft_events_pressed(game_init, 0, -1);
	return (anim);
}

int	ft_keyboard_down(t_game_instance *game_init, int anim)
{
	if (anim == 0)
	{
		game_init->game_objs.player = game_init->game_objs.player_down;
		anim = 1;
	}
	else if (anim == 1)
	{
		game_init->game_objs.player = game_init->game_objs.player_down2;
		anim = 0;
	}
	ft_events_pressed(game_init, 0, +1);
	return (anim);
}

int	ft_keyboard_left(t_game_instance *game_init, int anim)
{
	if (anim == 0)
	{
		game_init->game_objs.player = game_init->game_objs.player_left;
		anim = 1;
	}
	else if (anim == 1)
	{
		game_init->game_objs.player = game_init->game_objs.player_left2;
		anim = 0;
	}
	ft_events_pressed(game_init, -1, 0);
	return (anim);
}

int	ft_keyboard_right(t_game_instance *game_init, int anim)
{
	if (anim == 0)
	{
		game_init->game_objs.player = game_init->game_objs.player_right;
		anim = 1;
	}
	else if (anim == 1)
	{
		game_init->game_objs.player = game_init->game_objs.player_right2;
		anim = 0;
	}
	ft_events_pressed(game_init, +1, 0);
	return (anim);
}
