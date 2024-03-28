/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:15:20 by ehay              #+#    #+#             */
/*   Updated: 2024/03/28 16:55:27 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_locate_player(t_game_instance *game_init)
{
	int	col;
	int	row;

	row = 0;
	while (game_init->map_init.matrice[row] != NULL)
	{
		col = 0;
		while (game_init->map_init.matrice[row][col] != '\0')
		{
			if (game_init->map_init.matrice[row][col] == PLAYER)
			{
				game_init->positions_init.player_row = row;
				game_init->positions_init.player_col = col;
				return ;
			}
			col++;
		}
		row++;
	}
}

int	ft_print_shell(t_game_instance *game_init)
{
	static int	previous_count_movements = -1;
	int			current_count_movements;

	current_count_movements = game_init->game_data.count_movements;
	if (current_count_movements != previous_count_movements)
	{
		ft_printf("Move : %d\n", current_count_movements);
		previous_count_movements = current_count_movements;
	}
	return (1);
}

int	ft_events_pressed(t_game_instance *game_init, int column, int row)
{
	int	new_row;
	int	new_col;
	int	current_tile;

	ft_locate_player(game_init);
	new_row = game_init->positions_init.player_row + row;
	new_col = game_init->positions_init.player_col + column;
	current_tile = game_init->map_init.matrice[new_row][new_col];
	if (current_tile == EMPTY || current_tile == COLLECTIBLE)
	{
		game_init->map_init.matrice[new_row][new_col] = PLAYER;
		game_init->map_init.matrice[game_init->positions_init.player_row]
		[game_init->positions_init.player_col] = EMPTY;
		game_init->positions_init.player_row = new_row;
		game_init->positions_init.player_col = new_col;
		if (current_tile == COLLECTIBLE)
			game_init->game_data.count_collectible--;
		game_init->game_data.count_movements++;
	}
	else if (current_tile == EXIT
		&& game_init->game_data.count_collectible == 0)
		ft_win(game_init);
	else if (current_tile == ENNEMIES)
		ft_exit_program(game_init);
	return (ft_print_shell(game_init));
}

int	ft_player_moves(t_game_instance *game_init)
{
	char	*movements;

	movements = ft_itoa (game_init->game_data.count_movements);
	mlx_string_put(game_init->mlx_ptr, game_init->win_ptr,
		20, 16, 0x00FFFFFF, movements);
	free(movements);
	return (0);
}

int	ft_animbeforemap(void *param)
{
	t_game_instance	*game_init;

	game_init = (t_game_instance *)param;
	ft_player_moves(game_init);
	ft_anim_collectable(game_init);
	ft_map_draw(game_init);
	return (0);
}


void	ft_gameplay_start(t_game_instance *game_init)
{
	mlx_hook(game_init->win_ptr, 17, 0, ft_exit_program, game_init);
	mlx_hook(game_init->win_ptr, 2, (1L << 0), ft_check_keyboard, game_init);
	mlx_loop_hook(game_init->mlx_ptr, &ft_animbeforemap, game_init);
}
