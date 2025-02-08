/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:47:02 by sberete           #+#    #+#             */
/*   Updated: 2025/01/15 19:47:03 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *s, int *len);
void	ft_putnbr(int nb, int *len);
void	ft_u_int(unsigned int nb, int *len);
void	ft_putnbr_hex_lower(unsigned long nb, int *len);
void	ft_putnbr_hex_upper(unsigned long nb, int *len);
void	ft_ptr(void *ptr, int *len);

#endif