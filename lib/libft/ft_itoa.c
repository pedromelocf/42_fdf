/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:58:45 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/17 19:01:42 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	ft_count_decimal_houses(int n)
{
	long int	number1;
	size_t		size_alloc;

	number1 = n;
	size_alloc = 0;
	while (number1 != 0)
	{
		size_alloc++;
		number1 = number1 / 10;
	}
	return (size_alloc);
}

static char	*ft_increment_itoa_string(size_t decimal_houses, size_t index,
		char *string, long int number)
{
	while (decimal_houses != index)
	{
		decimal_houses--;
		string[decimal_houses] = number % 10 + '0';
		number = number / 10;
	}
	return (string);
}

char	*ft_itoa(int n)
{
	char		*string;
	size_t		decimal_houses;
	size_t		index;
	long int	number;

	index = 0;
	number = n;
	decimal_houses = ft_count_decimal_houses(n);
	if (number <= 0)
		decimal_houses++;
	string = (char *)malloc(decimal_houses + 1 * sizeof(char));
	if (!(string))
		return (NULL);
	if (number < 0)
	{
		number *= -1;
		index++;
		string[0] = '-';
	}
	string[decimal_houses] = '\0';
	if (number == 0)
		string[0] = '0';
	string = ft_increment_itoa_string(decimal_houses, index, string, number);
	return (string);
}
