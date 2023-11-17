/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:13:46 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/17 19:02:47 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while ((s1[i] && s2[i]) && (i < n) && !j)
	{
		j = ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if ((i < n) && s1[i] != s2[i] && !j)
		j = ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (j);
}
