/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:07:38 by sberete           #+#    #+#             */
/*   Updated: 2025/01/15 20:00:38 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*s1_1;
	unsigned const char	*s2_2;
	size_t				i;

	s1_1 = s1;
	s2_2 = s2;
	i = 0;
	while (s1_1[i] == s2_2[i] && i < n)
		i++;
	if (i >= n)
		return (0);
	return (s1_1[i] - s2_2[i]);
}

/*
int	main(void)
{
	char	s1[20] = "Je suis a";
	char	s2[20] = "Je suis b";

	printf(""%d", ft_memcmp(s1, s2, 0));
}
*/