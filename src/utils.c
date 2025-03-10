/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:31:32 by sxriimu           #+#    #+#             */
/*   Updated: 2025/03/07 18:31:39 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complexe	complex_add(t_complexe a, t_complexe b)
{
	t_complexe	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	return (res);
}

t_complexe	complex_square(t_complexe z)
{
	t_complexe	res;

	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = 2 * z.x * z.y;
	return (res);
}

float	complex_mod(t_complexe z)
{
	return (sqrtf(z.x * z.x + z.y * z.y));
}

t_complexe	julia_set(char *argv)
{
	t_complexe	c;

	if (argv[0] == '1' && !argv[1])
	{
		c.x = 0.285;
		c.y = 0.01;
	}
	else if (argv[0] == '2' && !argv[1])
	{
		c.x = -0.7;
		c.y = 0.27015;
	}
	else if (argv[0] == '3' && !argv[1])
	{
		c.x = -0.8;
		c.y = 0.156;
	}
	else if (argv[0] == '4' && !argv[1])
	{
		c.x = 0.37;
		c.y = -0.2;
	}
	else
		param_available();
	return (c);
}
