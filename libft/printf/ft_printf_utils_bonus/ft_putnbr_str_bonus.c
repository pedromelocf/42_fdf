/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_str_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:34:44 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/10/09 15:17:25 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf_bonus.h"

static int	ft_putnbr_recursive_bonus(int nb, int *length)
{
	if (nb < 0)
	{
		*length += ft_putchar_bonus('-');
		if (nb == -2147483648)
		{
			*length += ft_putchar_bonus('2');
			nb += 2000000000;
		}
		nb *= -1;
	}
	if (nb < 10)
		*length += ft_putchar_bonus(nb + '0');
	else
	{
		ft_putnbr_recursive_bonus(nb / 10, length);
		ft_putnbr_recursive_bonus(nb % 10, length);
	}
	return (*length);
}

int	ft_putnbr_str_bonus(int nb, const char *str, int i)
{
	int	length;

	length = 0;
	if ((str[i - 1] == ' ' || str[i - 1] == '+') && (nb >= 0))
		length += ft_putchar_bonus(str[i - 1]);
	ft_putnbr_recursive_bonus(nb, &length);
	return (length);
}
