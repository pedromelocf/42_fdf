/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:02:17 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/17 19:02:59 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_string;
	size_t	s1_lenght;
	size_t	index;
	size_t	counter;

	counter = 0;
	s1_lenght = ft_strlen(s1);
	index = 0;
	if (!s1)
		return (NULL);
	while (s1[index] && ft_strchr(set, s1[index]) != NULL)
		index++;
	while (index < s1_lenght && ft_strrchr(set, s1[s1_lenght - 1]) != NULL)
		s1_lenght--;
	trimmed_string = (char *)malloc(sizeof(char) * (s1_lenght - index + 1));
	if (trimmed_string == NULL)
		return (NULL);
	while (counter < s1_lenght - index + counter)
	{
		trimmed_string[counter] = s1[index];
		index++;
		counter++;
	}
	trimmed_string[counter] = '\0';
	return (trimmed_string);
}
