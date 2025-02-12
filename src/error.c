/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:47:35 by sberete           #+#    #+#             */
/*   Updated: 2025/02/09 21:36:46 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	malloc_error(void)
{
	perror("Malloc faillure");
	exit(0);
}

void	param_available(void)
{
	ft_printf("The available parameters are :\nJulia\nMandelbrot\nBurningship\n");
	exit(0);
}
