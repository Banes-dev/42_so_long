/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:13:08 by ehay              #+#    #+#             */
/*   Updated: 2024/02/27 15:44:22 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_data
{
    void	*mlx_ptr;
    void	*win_ptr;
}	t_data;

int	handle_keypress(int keysym, t_data *data)
{
    if (keysym == ESC)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        data->win_ptr = NULL;
    }
    return (0);
}

int	render(t_data *data)
{
    /* if window has been destroyed, we don't want to put the pixel ! */
    if (data->win_ptr != NULL)
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, 
            WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 0xFF0000);
    return (0);
}

int	main(void)
{
    void *mlx_ptr;
    void *win_ptr;

    // Initialisation de la connexion avec le serveur graphique
    mlx_ptr = mlx_init();
    
    // Création d'une fenêtre de 500x500 pixels
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Ma fenêtre");

    // Boucle pour maintenir la fenêtre ouverte jusqu'à ce qu'elle soit fermée
    mlx_loop(mlx_ptr);

    return 0;
}

// int	main(int argc, char **argv)
// {
	
// 	// if (argc == 2)
// 	// {
// 	// 	// code
// 	// }
// 	// else
// 	// {
// 	// 	// erreur
// 	// }
// 	return (0);
// }
