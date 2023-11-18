/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:34:37 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/17 21:20:07 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_putnbr_hex(unsigned long int nbr, int index, char *base)
{
	unsigned int	reminder;
	int				length;
	char			*hexnumber;

	length = 0;
	hexnumber = malloc(sizeof(char) * 32);
	while (nbr > 0)
	{
		reminder = nbr % 16;
		hexnumber[index++] = base[reminder];
		nbr /= 16;
	}
	hexnumber[index] = '\0';
	while (index > 0)
		length += ft_putchar(hexnumber[--index]);
	hexnumber[index] = '\0';
	free(hexnumber);
	return (length);
}
