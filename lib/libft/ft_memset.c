/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:10:28 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/17 19:02:01 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	counter;
	char	*ptr;

	counter = 0;
	ptr = s;
	while (counter < n)
	{
		ptr[counter] = c;
		counter++;
	}
	return (s);
}
