/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:24:54 by ehay              #+#    #+#             */
/*   Updated: 2024/03/15 15:46:29 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int num_error)
{
	if (num_error == 1)
	{
		ft_printf("\033[96mError : \033[91mnot two args.\033[0m\n");
		ft_printf("\033[96mTry : \033[33m./so_long <map>.ber\033[0m\n");
	}
	else if (num_error == 2)
	{
		// ft_printf("\033[96mError : \033[91mnot two args.\033[0m\n");
		// ft_printf("\033[96mTry : \033[33m./so_long <map>.ber\n");
	}
	else if (num_error == 666)
	{
		ft_printf("\033[96mError : \033[91mMalloc issue.\033[0m\n");
	}
	exit(1);
}
