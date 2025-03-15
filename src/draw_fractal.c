/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:14:23 by sberete           #+#    #+#             */
/*   Updated: 2025/03/15 13:50:23 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complexe	set_c(t_data *fractol, t_complexe *z)
{
	t_complexe	c;

	if (ft_strncmp(fractol->argv[1], "julia", 5) && fractol->argv[2])
		c = julia_set(fractol->argv[2]);
	else
	{
		c.x = z->x;
		c.y = z->y;
	}
	return (c);
}

static int	get_color(t_data *fractol, int i)
{
	float	ratio;
	int		color;

	ratio = (float)i / fractol->max_iter;
	if (fractol->color_scheme == 0)
		color = (((int)(ratio * 128)) << 16) | (((int)(ratio
						* 0)) << 8) | ((int)(ratio * 255));
	else if (fractol->color_scheme == 1)
		color = (((int)(ratio * 255)) << 8) | ((int)((1 - ratio) * 255));
	else if (fractol->color_scheme == 2)
		color = WHITE;
	return (color);
}

static void	draw_pixel(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static int	compute_color_at_pixel(int x, int y, t_data *fractol)
{
	t_complexe	z;
	t_complexe	c;
	int			i;

	z.x = ((x - WIDTH / 2.0) * 4.0 / WIDTH) * fractol->zoom;
	z.y = ((y - HEIGHT / 2.0) * 4.0 / HEIGHT) * fractol->zoom;
	c = set_c(fractol, &z);
	i = 0;
	while (i < fractol->max_iter)
	{
		z = complex_add(complex_square(z), c);
		if (complex_mod(z) > 2.0)
			return (get_color(fractol, i));
		i++;
	}
	return (BLACK);
}

void	render(t_data *fractol)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = compute_color_at_pixel(x, y, fractol);
			draw_pixel(x, y, &fractol->img, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img_ptr, 0,
		0);
}
