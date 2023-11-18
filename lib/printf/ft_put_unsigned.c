/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:38:30 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/17 21:19:56 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_put_unsigned(long int nb)
{
	int	length;

	length = 0;
	if (nb < 0)
		nb = 4294967295 + nb + 1;
	if (nb < 10)
		length += ft_putchar(nb + '0');
	else
	{
		length += ft_putnbr(nb / 10);
		length += ft_putnbr(nb % 10);
	}
	return (length);
}
