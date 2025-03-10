/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:47:35 by sberete           #+#    #+#             */
/*   Updated: 2025/03/07 18:34:00 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	param_available(void)
{
	ft_printf("Available parameters :\n");
	ft_printf("julia <1> || <2> || <3> || <4>\nmandelbrot\n");
	exit(0);
}
