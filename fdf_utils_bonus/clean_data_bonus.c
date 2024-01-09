/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:06:24 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/09 15:29:06 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	clean_data(t_map *s_map)
{
	t_map	*remove;

	while (s_map != NULL)
	{
		remove = s_map;
		s_map = s_map->next;
		if (remove->s_coordinate != NULL)
		{
			free(remove->s_coordinate);
			remove->s_coordinate = NULL;
		}
		free(remove);
	}
}

void	clean_split(char **split_result)
{
	int	x;

	x = 0;
	while (split_result[x])
		free(split_result[x++]);
	free(split_result);
}

void	clean_matrix(float **map_matrix)
{
	int	x;

	x = 0;
	while (map_matrix[x] != NULL)
		free(map_matrix[x++]);
	free(map_matrix);
}
