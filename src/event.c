/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:12:46 by sberete           #+#    #+#             */
/*   Updated: 2025/03/07 19:12:59 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	close_mlx(t_data *fractol)
{
	mlx_destroy_window(fractol->mlx, fractol->win);
	mlx_destroy_image(fractol->mlx, fractol->img.img_ptr);
	mlx_destroy_display(fractol->mlx);
	free(fractol->mlx);
	exit(0);
}

int	key_func(int keycode, t_data *ap)
{
	if (keycode == 65307)
		close_mlx(ap);
	else if (keycode == 99)
	{
		ap->color_scheme = (ap->color_scheme + 1) % 3;
		render(ap);
	}
	return (0);
}

int	mouse_func(int keycode, int x, int y, t_data *fractol)
{
	(void)x;
	(void)y;
	if (keycode == 4)
		fractol->zoom *= 0.90;
	else if (keycode == 5)
		fractol->zoom *= 1.10;
	render(fractol);
	return (0);
}

int	hook_func(t_data *ap)
{
	close_mlx(ap);
	return (0);
}
