/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:05:20 by sberete           #+#    #+#             */
/*   Updated: 2025/02/09 21:55:24 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "ft_printf.h"
# include "libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define BLANC 0x00FFFFFF

# define WIDTH 800
# define HEIGHT 800

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*name;
}			t_data;

typedef struct s_complexe
{
	float	x;
	float	y;
}			t_complexe;

bool		check(int argc, char **argv);
int			key_func(int keycode, t_data *ap);
int			mous_func(int keycode, t_data *ap);
int			hook_func(t_data *ap);
void		malloc_error(void);
void		param_available(void);
void		fractol_init(t_data *fractol);

#endif