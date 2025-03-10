/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:12:46 by sberete           #+#    #+#             */
/*   Updated: 2025/03/10 01:11:59 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	close_mlx(t_data *fractol)
{
	mlx_destroy_window(fractol->mlx, fractol->win);
	mlx_destroy_image(fractol->mlx, fractol->img.img_ptr);
	mlx_destroy_display(fractol->mlx);
	free(fractol->mlx);
	exit(0);
}

static void	handle_arrow_keys(int keycode, t_data *ap)
{
	if (keycode == 65361)
	{
		ap->offset_x -= 0.05 * ap->zoom;
		render(ap);
	}
	else if (keycode == 65363)
	{
		ap->offset_x += 0.05 * ap->zoom;
		render(ap);
	}
	else if (keycode == 65362)
	{
		ap->offset_y -= 0.05 * ap->zoom;
		render(ap);
	}
	else if (keycode == 65364)
	{
		ap->offset_y += 0.05 * ap->zoom;
		render(ap);
	}
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
	else if (keycode == 65361 || keycode == 65363 || keycode == 65362
		|| keycode == 65364)
	{
		handle_arrow_keys(keycode, ap);
	}
	return (0);
}

int	mouse_func(int keycode, int x, int y, t_data *fractol)
{
	double	zoom_factor;
	double	old_zoom;

	if (keycode == 4)
		zoom_factor = 0.90;
	else if (keycode == 5)
		zoom_factor = 1.10;
	else
		return (0);
	old_zoom = fractol->zoom;
	fractol->zoom *= zoom_factor;
	fractol->offset_x += (x - WIDTH / 2.0) * (4.0 / WIDTH) * (old_zoom
			- fractol->zoom);
	fractol->offset_y += (y - HEIGHT / 2.0) * (4.0 / HEIGHT) * (old_zoom
			- fractol->zoom);
	render(fractol);
	return (0);
}

int	hook_func(t_data *ap)
{
	close_mlx(ap);
	return (0);
}
