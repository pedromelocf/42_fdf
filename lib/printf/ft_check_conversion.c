/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:58:43 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/17 21:19:38 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_check_conversion(const char *str, int i, va_list args)
{
	int	length;

	length = 0;
	if (str[i] == 'c')
		length += ft_putchar(va_arg(args, int));
	if (str[i] == 's')
		length += ft_putstr(va_arg(args, char *));
	if (str[i] == 'p')
		length += ft_put_voidpointer(va_arg(args, char *));
	if (str[i] == 'd' || str[i] == 'i')
		length += ft_putnbr(va_arg(args, int));
	if (str[i] == 'u')
		length += ft_put_unsigned(va_arg(args, int));
	if (str[i] == 'x' || str[i] == 'X')
		length += ft_put_hex(va_arg(args, unsigned int), str, i);
	if (str[i] == '%')
		length += ft_putchar('%');
	return (length);
}
