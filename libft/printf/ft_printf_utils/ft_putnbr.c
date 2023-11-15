/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:00:24 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/10/09 15:17:39 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	ft_putnbr_recursive(int nb, int *length)
{
	if (nb < 0)
	{
		*length += ft_putchar('-');
		if (nb == -2147483648)
		{
			*length += ft_putchar('2');
			nb += 2000000000;
		}
		nb *= -1;
	}
	if (nb < 10)
		*length += ft_putchar(nb + '0');
	else
	{
		ft_putnbr_recursive(nb / 10, length);
		ft_putnbr_recursive(nb % 10, length);
	}
	return (*length);
}

int	ft_putnbr(int nb)
{
	int	length;

	length = 0;
	ft_putnbr_recursive(nb, &length);
	return (length);
}
