/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_void_pointer_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:38:32 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/10/09 14:32:32 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf_bonus.h"

int	ft_put_voidpointer_bonus(char *str)
{
	int	length;

	length = 0;
	if (!str)
		return (ft_putstr_bonus("(nil)"));
	length += ft_putstr_bonus("0x");
	length += ft_putnbr_base_bonus((unsigned long int)str, "0123456789abcdef");
	return (length);
}
