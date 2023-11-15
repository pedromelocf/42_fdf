/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:50:02 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/10/09 14:32:27 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf_bonus.h"

int	ft_put_hex_bonus(unsigned long int nbr, const char *str, int i)
{
	int	index;
	int	length;

	length = 0;
	index = 0;
	if (nbr == 0)
		return (ft_putchar_bonus('0'));
	if (str[i] == 'x')
	{
		if (str[i - 1] == '#')
			length = ft_putstr_bonus("0x");
		length += ft_putnbr_hex_bonus(nbr, index, NONCAPHEX);
	}
	if (str[i] == 'X')
	{
		if (str[i - 1] == '#')
			length = ft_putstr_bonus("0X");
		length += ft_putnbr_hex_bonus(nbr, index, CAPHEX);
	}
	return (length);
}
