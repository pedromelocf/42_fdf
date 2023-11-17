/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:00:42 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/17 19:02:53 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	s_len;

	s_len = ft_strlen(s);
	if (c == 0)
		return ((char *)&s[s_len]);
	while (s_len >= 0)
	{
		if (s[s_len] == (unsigned char)c)
			return ((char *)&s[s_len]);
		s_len--;
	}
	return (NULL);
}
