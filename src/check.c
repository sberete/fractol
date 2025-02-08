/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:40:38 by sberete           #+#    #+#             */
/*   Updated: 2025/02/08 22:54:00 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

bool	check_mandelbrot(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			if (argv[1][0] == 'M' || argv[1][0] == 'm' || argv[1][1] == 'A'
				|| argv[1][1] == 'a' || argv[1][2] == 'n' || argv[1][2] == 'N'
				|| argv[1][3] == 'D' || argv[1][3] == 'd' || argv[1][4] == 'E'
				|| argv[1][4] == 'e' || argv[1][5] == 'L' || argv[1][5] == 'l'
				|| argv[1][6] == 'B' || argv[1][6] == 'b' || argv[1][7] == 'R'
				|| argv[1][7] == 'r' || argv[1][8] == 'O' || argv[1][8] == 'o'
				|| argv[1][9] == 'T' || argv[1][9] == 't')
				i++;
			else
				break ;
		}
		if (i != 10)
			return (false);
	}
	return (true);
}

bool	check_julia(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			if (argv[1][0] == 'J' || argv[1][0] == 'j' || argv[1][1] == 'U'
				|| argv[1][1] == 'u' || argv[1][2] == 'L' || argv[1][2] == 'l'
				|| argv[1][3] == 'I' || argv[1][3] == 'i' || argv[1][4] == 'A'
				|| argv[1][4] == 'a')
				i++;
			else
				break ;
		}
		if (i != 5)
			return (false);
	}
	else if (argc == 3)
	{
		if (argv[2][0] != '1' || argv[2][0] != '2')
			return (false);
		printf("d\n");
		while (argv[1][i] != '\0')
		{
			if (argv[1][0] == 'J' || argv[1][0] == 'j' || argv[1][1] == 'U'
				|| argv[1][1] == 'u' || argv[1][2] == 'L' || argv[1][2] == 'l'
				|| argv[1][3] == 'I' || argv[1][3] == 'i' || argv[1][4] == 'A'
				|| argv[1][4] == 'a')
				i++;
			else
				break ;
		}
		printf("%d\n", i);
		if (i != 5)
			return (false);
	}
	return (true);
}

bool	check(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
		return (false);
	if (check_mandelbrot(argc, argv) && argc == 2)
		return (true);
	if (check_julia(argc, argv) && (argc == 2 || argc == 3))
		return (true);
	return (false);
}
