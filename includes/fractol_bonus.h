/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:32:45 by sxriimu           #+#    #+#             */
/*   Updated: 2025/03/10 00:21:56 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "ft_printf.h"
# include "libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 800
# define HEIGHT 800

# define BLACK 0x000000 // RGB(0, 0, 0)
# define WHITE 0xFFFFFF // RGB(255, 255, 255)
# define RED 0xFF0000   // RGB(255, 0, 0)
# define GREEN 0x00FF00 // RGB(0, 255, 0)
# define BLUE 0x0000FF  // RGB(0, 0, 255)

typedef struct s_img
{
	void	*img_ptr;	// pointer to image struct
	char	*pixels_ptr;// points to the actual pixels
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_complexe
{
	float	x;
	float	y;
}			t_complexe;

typedef struct s_data
{
	char	**argv;
	char	*name;
	void	*mlx;
	void	*win;
	t_img	img;
	double	zoom;
	double	offset_x;
	double	offset_y;
	int		max_iter;
	int		color_scheme;
}			t_data;

t_complexe	complex_add(t_complexe a, t_complexe b);
t_complexe	complex_square(t_complexe z);
float		complex_mod(t_complexe z);
t_complexe	julia_set(char *argv);
void		render(t_data *fractol);
int			key_func(int keycode, t_data *ap);
int			mouse_func(int keycode, int x, int y, t_data *fractol);
int			hook_func(t_data *ap);
void		param_available(void);
void		fractol_init(t_data *fractol);

#endif
