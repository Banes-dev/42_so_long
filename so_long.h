/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:03:51 by ehay              #+#    #+#             */
/*   Updated: 2024/03/11 16:19:57 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "unistd.h"
# include "stdlib.h"          // malloc & free
# include "stdarg.h"          // fonction va_
# include "stddef.h"          // size_t
# include "limits.h"          // INT_MIN et INT_MAX
# include "mlx/mlx.h"

# define WINDOW_WIDTH 960
# define WINDOW_HEIGHT 540

# define ESC 65307
# define W 119
# define UP 65362
# define A 97
# define LEFT 65361
# define S 115
# define DOWN 65364
# define D 100
# define RIGHT 65363
# define R 114

////// UTILS
// ft_printf
int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_putpointer(void *adress);
int		ft_puthexalower(long double number);
int		ft_puthexaupper(long double number);

#endif