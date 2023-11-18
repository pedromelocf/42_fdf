/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:50:49 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/17 21:19:48 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_printf(const char *str, ...)
{
	short int	i;
	int			length;
	va_list		args;

	i = 0;
	length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			length += ft_check_conversion(str, i, args);
		}
		else
			length += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (length);
}
