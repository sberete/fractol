/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:47:15 by sberete           #+#    #+#             */
/*   Updated: 2025/01/15 19:47:16 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	checker(char c, va_list *ap, int *len)
{
	if (c == '%')
		ft_putchar('%', len);
	else if (c == 'c')
		ft_putchar(va_arg(*ap, int), len);
	else if (c == 's')
		ft_putstr(va_arg(*ap, char *), len);
	else if (c == 'd')
		ft_putnbr(va_arg(*ap, int), len);
	else if (c == 'i')
		ft_putnbr(va_arg(*ap, int), len);
	else if (c == 'u')
		ft_u_int(va_arg(*ap, int), len);
	else if (c == 'x')
		ft_putnbr_hex_lower(va_arg(*ap, int), len);
	else if (c == 'X')
		ft_putnbr_hex_upper(va_arg(*ap, int), len);
	else if (c == 'p')
		ft_ptr(va_arg(*ap, void *), len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			checker(format[++i], &ap, &len);
			i++;
		}
		else
			ft_putchar((char)format[i++], &len);
	}
	va_end(ap);
	return (len);
}
