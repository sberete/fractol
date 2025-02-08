/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:18:57 by sberete           #+#    #+#             */
/*   Updated: 2025/02/08 22:16:47 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_func(int keycode, t_data *ap)
{
	printf("key event %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(ap->mlx, ap->win);
		mlx_destroy_display(ap->mlx);
		free(ap->mlx);
		exit(0);
	}
	// if (keycode == une touche)
	//     choisir une touche pour changer la couleur
	// if (keycode == 65361)
	//     fleche de gauche, bouger l'image vers gauche
	// if (keycode == 65362)
	//     fleche du haut, bouger l'image vers le haut
	// if (keycode == 65363)
	//     fleche de droite, bouger l'image vers droite
	// if (keycode == 65364)
	//     fleche du bas, bouger l'image vers le bas
	return (0);
}

int	mous_func(int keycode, t_data *ap)
{
	(void)ap;
	printf("mouse event %d\n", keycode);
	// if (keycode == 4)
	//     zoom
	// else if(keycode == 5)
	//     dezoom
	return (0);
}

int	hook_func(t_data *ap)
{
	mlx_destroy_window(ap->mlx, ap->win);
	mlx_destroy_display(ap->mlx);
	free(ap->mlx);
	exit(0);
}



void	param_available(void)
{
	ft_printf("The available parameters are :\nJulia\nMandelbrot\nBurningship\n");
}

int	main(int argc, char **argv)
{
	t_data	ap;
	int		x;
	int		y;

	if (!check(argc, argv))
	{
		param_available();	
		return (1);
	}
	ft_memset(&ap, 0, sizeof(t_data));
	ap.mlx = mlx_init();
	ap.win = mlx_new_window(ap.mlx, 400, 400, "fractol");
	y = 50;
	while (y < 150)
	{
		x = 50;
		while (x < 150)
		{
			mlx_pixel_put(ap.mlx, ap.win, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	mlx_key_hook(ap.win, key_func, &ap);
	mlx_hook(ap.win, DestroyNotify, StructureNotifyMask, hook_func, &ap);
	mlx_mouse_hook(ap.win, mous_func, &ap);
	mlx_loop(ap.mlx);
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