/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:06:23 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/21 19:46:26 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

t_map	*map_read(const char *argv)
{
	t_map			*s_map;
	char			**split_result;
	char			*line;
	int				fd;
	int				x;
	int				y;

	fd = open(argv, O_RDONLY);
	y = 0;
	s_map = malloc(sizeof(t_map));
	s_map->s_coordinate = malloc(sizeof(t_coordinates));
	while ((line = get_next_line(fd)) != NULL)
	{
		x = 0;
		split_result = ft_split(line, ' ');
		while (split_result[x] != NULL)
		{
			s_map->s_coordinate->x = x;
			s_map->s_coordinate->y = y;
			s_map->s_coordinate->z = ft_atoi(split_result[x]);
			s_map->content = s_map;
			s_map->next = NULL;
			x++;
		}
		free(split_result);
		y++;
	}
	close(fd);
	return (s_map);
}
