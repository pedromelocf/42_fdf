/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:38:30 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/10/09 14:48:25 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf_bonus.h"

int	ft_put_unsigned_bonus(long int nb)
{
	int	length;

	length = 0;
	if (nb < 0)
		nb = 4294967295 + nb + 1;
	if (nb < 10)
		length += ft_putchar_bonus(nb + '0');
	else
	{
		length += ft_putnbr_bonus(nb / 10);
		length += ft_putnbr_bonus(nb % 10);
	}
	return (length);
}
