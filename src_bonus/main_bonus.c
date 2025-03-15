/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:18:57 by sberete           #+#    #+#             */
/*   Updated: 2025/03/15 12:59:36 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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
	mlx_loop(fractol.mlx);
}
