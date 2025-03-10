/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:18:57 by sberete           #+#    #+#             */
/*   Updated: 2025/03/07 18:28:22 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void	drawing(t_data *fractol, t_complexe c, int max_iter)
// {
// 	if (ft_strncmp(fractol->name, "julia", 5))
// 		julia(fractol);
// 	else
// 		mandelbrot(fractol);
// }

int	main(int argc, char **argv)
{
	t_data	fractol;

	if ((argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10))
		|| (ft_strncmp(argv[1], "julia", 5) && argc == 3))
	{
		ft_memset(&fractol, 0, sizeof(t_data));
		fractol.argv = argv;
		fractol_init(&fractol);
	}
	else
		param_available();
	render(&fractol);
	mlx_key_hook(fractol.win, key_func, &fractol);
	mlx_hook(fractol.win, DestroyNotify, StructureNotifyMask, hook_func,
		&fractol);
	mlx_mouse_hook(fractol.win, mouse_func, &fractol);
	mlx_loop(fractol.mlx);
}
