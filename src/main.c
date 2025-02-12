/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:18:57 by sberete           #+#    #+#             */
/*   Updated: 2025/02/09 21:49:04 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	fractol;

	if (argc == 2 && (ft_strncmp(argv[1], "mandelbrot", 10)
			|| ft_strncmp(argv[1], "julia", 5)))
	{
		ft_memset(&fractol, 0, sizeof(t_data));
		fractol.name = argv[1];
		fractol_init(&fractol);
	}
	else
		param_available();
	mlx_key_hook(fractol.win, key_func, &fractol);
	mlx_hook(fractol.win, DestroyNotify, StructureNotifyMask, hook_func,
		&fractol);
	mlx_mouse_hook(fractol.win, mous_func, &fractol);
	mlx_loop(fractol.mlx);
}

/*
	void *mlx;
	void *win;
	mlx = mlx_init() :
		-> permet de faire la connexion entre le programme et le serveur graphique
	win = mlx_new_window(mlx, taille x, taille y, "nom de la fenetre") :
		->cree la fenetre du x sur y taille
	mlx_pixel_put(mlx, win, int x, int y, 0x00FFFFFF)
	-> permet d'afficher un pixel sur la fenetre
*/