/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:47:35 by sberete           #+#    #+#             */
/*   Updated: 2025/03/09 17:02:27 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	param_available(void)
{
	ft_printf("Available parameters :\n");
	ft_printf("julia <1> || <2> || <3> || <4>\n");
	ft_printf("mandelbrot\nburningship\n");
	exit(0);
}
