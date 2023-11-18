/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:44:22 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/17 21:20:04 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_putnbr_base(unsigned long int nbr, char *base)
{
	char			*hexnumber;
	int				index;
	unsigned int	reminder;
	int				base_len;

	base_len = ft_strlen(base);
	index = 0;
	if (nbr == 0)
		return (ft_putchar('0'));
	hexnumber = malloc(sizeof(char) * 32);
	while (nbr > 0)
	{
		reminder = nbr % base_len;
		hexnumber[index++] = base[reminder];
		nbr /= base_len;
	}
	hexnumber[index] = '\0';
	while (index > 0)
		ft_putchar(hexnumber[--index]);
	base_len = ft_strlen(hexnumber);
	free(hexnumber);
	return (base_len);
}
