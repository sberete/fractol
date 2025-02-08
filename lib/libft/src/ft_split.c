/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:07:38 by sberete           #+#    #+#             */
/*   Updated: 2025/01/28 18:41:40 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	count_word(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] != '\0' && (str[i] == c))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && (!(str[i] == c)))
			i++;
	}
	return (count);
}

void	ft_fill(int size, char **dest, char const *str, char c)
{
	int	i;
	int	j;
	int	k;
	int	m;

	i = 0;
	j = 0;
	while (j < size && str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == c))
			i++;
		k = i;
		while (str[k] != '\0' && (!(str[k] == c)))
			k++;
		dest[j] = malloc(sizeof(char) * (k - i) + 1);
		if (!dest)
			return (free_tab(dest));
		m = 0;
		while (i < k)
			dest[j][m++] = str[i++];
		dest[j][m] = '\0';
		j++;
	}
	dest[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		size;

	size = count_word(s, c);
	str = malloc(sizeof(char *) * (size + 1));
	if (!str)
		return (NULL);
	ft_fill(size, str, s, c);
	return (str);
}
/*
int	main(void)
{
	int		i;
	char	*str;
	char	**moussa;

	i = 0;
	str = "l d e";
	moussa = ft_split(str, ' ');
	while (moussa[i] != NULL)
	{
		printf(""%s\n", moussa[i]);
		i++;
	}
	free(moussa);
}
*/
