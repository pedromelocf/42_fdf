/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:00:03 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/10/09 14:32:45 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf_bonus.h"

int	ft_putstr_bonus(char *str)
{
	int	length;

	length = 0;
	if (!str)
		return (ft_putstr_bonus("(null)"));
	while (str[length])
	{
		ft_putchar_bonus(str[length]);
		length++;
	}
	return (length);
}
