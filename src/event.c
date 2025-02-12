/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:12:46 by sberete           #+#    #+#             */
/*   Updated: 2025/02/09 21:48:54 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_func(int keycode, t_data *ap)
{
	printf("key event %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(ap->mlx, ap->win);
		mlx_destroy_image(ap->mlx, ap->img);
		mlx_destroy_display(ap->mlx);
		free(ap->mlx);
		exit(0);
	}
	// if (keycode == une touche)
	//     choisir une touche pour changer la couleur
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
	mlx_destroy_image(ap->mlx, ap->img);
	mlx_destroy_display(ap->mlx);
	free(ap->mlx);
	exit(0);
}