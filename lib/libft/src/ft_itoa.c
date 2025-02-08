/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:07:38 by sberete           #+#    #+#             */
/*   Updated: 2025/01/15 20:00:32 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	nbrlen(long n)
{
	int	nb;

	nb = 0;
	if (n < 0)
	{
		n *= -1;
		nb++;
	}
	if (n == 0)
		nb++;
	while (n > 0)
	{
		n = n / 10;
		nb++;
	}
	return (nb);
}

char	*ft_itoa(int n)
{
	char	*base;
	char	*str;
	long	nb;
	int		i;

	base = "0123456789";
	nb = n;
	i = nbrlen(nb);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
	}
	while (nb > 0)
	{
		str[--i] = base[nb % 10];
		nb = nb / 10;
	}
	return (str);
}
/*
int	main(void)
{
	char	*x;

	x = ft_itoa(0);
	printf(""%s", x);
}
*/