/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:47:12 by sberete           #+#    #+#             */
/*   Updated: 2025/01/15 19:47:13 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int *len)
{
	long	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar('-', len);
		nbr *= -1;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10, len);
	ft_putchar(nbr % 10 + '0', len);
}

void	ft_u_int(unsigned int nb, int *len)
{
	if (nb > 9)
		ft_u_int(nb / 10, len);
	ft_putchar(nb % 10 + '0', len);
}

void	ft_putnbr_hex_lower(unsigned long nb, int *len)
{
	char	*hex_digit;

	hex_digit = "0123456789abcdef";
	if (nb >= 16)
		ft_putnbr_hex_lower(nb / 16, len);
	ft_putchar(hex_digit[nb % 16], len);
}

void	ft_putnbr_hex_upper(unsigned long nb, int *len)
{
	char	*hex_digit;

	hex_digit = "0123456789ABCDEF";
	if (nb >= 16)
		ft_putnbr_hex_upper(nb / 16, len);
	ft_putchar(hex_digit[nb % 16], len);
}

void	ft_ptr(void *ptr, int *len)
{
	unsigned long	adress;

	if (ptr == 0)
	{
		ft_putstr("(nil)", len);
		return ;
	}
	adress = (unsigned long)ptr;
	ft_putstr("0x", len);
	ft_putnbr_hex_lower(adress, len);
}
