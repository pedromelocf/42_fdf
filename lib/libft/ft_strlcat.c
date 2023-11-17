/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:06:05 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/17 19:02:33 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_lenght;
	size_t	dst_lenght;
	size_t	i;

	src_lenght = 0;
	dst_lenght = 0;
	i = 0;
	while (dst[dst_lenght])
		dst_lenght++;
	while (src[src_lenght])
		src_lenght++;
	if (size <= dst_lenght)
		return (src_lenght + size);
	while (src[i] && dst_lenght + i < size - 1)
	{
		dst[dst_lenght + i] = src[i];
		i++;
	}
	dst[dst_lenght + i] = '\0';
	return (dst_lenght + src_lenght);
}
