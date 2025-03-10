/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:18:57 by sberete           #+#    #+#             */
/*   Updated: 2025/03/10 01:10:47 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	mlx_hookes(t_data *fractol)
{
	mlx_key_hook(fractol->win, key_func, fractol);
	mlx_hook(fractol->win, DestroyNotify, StructureNotifyMask, hook_func,
		fractol);
	mlx_mouse_hook(fractol->win, mouse_func, fractol);
}

int	main(int argc, char **argv)
{
	t_data	fractol;

	if ((argc == 2 && (ft_strncmp(argv[1], "mandelbrot", 10)
				|| ft_strncmp(argv[1], "burningship", 11)))
		|| (ft_strncmp(argv[1], "julia", 5) && argc == 3))
	{
		ft_memset(&fractol, 0, sizeof(t_data));
		fractol.argv = argv;
		fractol_init(&fractol);
	}
	else
		param_available();
	render(&fractol);
	mlx_hookes(&fractol);
	mlx_loop(fractol.mlx);
}
/*
2 mangues
2 frambroise
2 el morgen
1 mms
2 beurre salé speculos
2 kinder bueno
1 oreo
*/