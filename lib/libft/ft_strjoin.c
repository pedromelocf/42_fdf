/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:02:12 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/17 19:02:30 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstring;
	size_t	counter;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	counter = 0;
	newstring = (char *)malloc(sizeof(char) * s1_len + s2_len + 1);
	if (newstring == NULL)
		return (NULL);
	while (counter < s1_len + s2_len)
	{
		if (counter < s1_len)
			newstring[counter] = s1[counter];
		if (counter >= s1_len && counter < s1_len + s2_len)
			newstring[counter] = s2[counter - s1_len];
		counter++;
	}
	newstring[counter] = '\0';
	return (newstring);
}
