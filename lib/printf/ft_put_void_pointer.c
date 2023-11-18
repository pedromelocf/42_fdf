/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_void_pointer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:38:32 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/17 21:19:58 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_put_voidpointer(char *str)
{
	int	length;

	length = 0;
	if (!str)
		return (ft_putstr("(nil)"));
	length += ft_putstr("0x");
	length += ft_putnbr_base((unsigned long int)str, "0123456789abcdef");
	return (length);
}
