/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:06:24 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/28 16:09:30 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	clean_data(t_map	*s_map)
{
	t_map	*remove;

	while (s_map != NULL)
	{
		remove = s_map;
		s_map = s_map->next;
		if	(remove->s_coordinate != NULL)
		{
			free(remove->s_coordinate);
			remove->s_coordinate = NULL;
		}
		free(remove);
	}
}

void	clean_split(char	**split_result)
{
	int x;

	x = 0;
	while(split_result[x])
		free(split_result[x++]);
	free(split_result);
}
