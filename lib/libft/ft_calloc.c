/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:15:22 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/17 19:01:30 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*array;
	size_t	index;
	size_t	maxint_validator;

	index = 0;
	maxint_validator = (nmemb * size);
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (maxint_validator / nmemb != size)
		return (NULL);
	array = (void *)malloc(size * nmemb);
	if (array == NULL)
		return (NULL);
	while (index < nmemb * size)
	{
		array[index] = '\0';
		index++;
	}
	return (array);
}
