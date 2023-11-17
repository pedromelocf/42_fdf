/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:58:29 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/17 19:02:41 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	counter;
	size_t	index;
	char	*string;

	index = 0;
	counter = ft_strlen(s);
	string = (char *)malloc(sizeof(char) * counter + 1);
	if (string == NULL)
		return (NULL);
	string[counter] = '\0';
	while (index < counter)
	{
		string[index] = f(index, s[index]);
		index++;
	}
	return (string);
}
