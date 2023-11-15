/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_conversion_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:58:43 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/10/09 14:46:14 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf_bonus.h"

int	ft_check_conversion_bonus(const char *str, int i, va_list args)
{
	int	length;

	length = 0;
	if (str[i] == 'c')
		length += ft_putchar_bonus(va_arg(args, int));
	if (str[i] == 's')
		length += ft_putstr_bonus(va_arg(args, char *));
	if (str[i] == 'p')
		length += ft_put_voidpointer_bonus(va_arg(args, char *));
	if (str[i] == 'd' || str[i] == 'i')
		length += ft_putnbr_str_bonus(va_arg(args, int), str, i);
	if (str[i] == 'u')
		length += ft_put_unsigned_bonus(va_arg(args, int));
	if (str[i] == 'x' || str[i] == 'X')
		length += ft_put_hex_bonus(va_arg(args, unsigned int), str, i);
	if (str[i] == '%')
		length += ft_putchar_bonus('%');
	return (length);
}
