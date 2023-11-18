/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:50:02 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/17 21:19:53 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_put_hex(unsigned long int nbr, const char *str, int i)
{
	int	index;
	int	length;

	length = 0;
	index = 0;
	if (nbr == 0)
		return (ft_putchar('0'));
	if (str[i] == 'x')
		length += ft_putnbr_hex(nbr, index, NONCAPHEX);
	if (str[i] == 'X')
		length += ft_putnbr_hex(nbr, index, CAPHEX);
	return (length);
}
