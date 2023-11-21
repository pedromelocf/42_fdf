/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:06:23 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/20 22:18:57 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

t_coordinates	**map_read(const char *argv)
{
	int				fd;
	int				x;
	int				y;
	t_coordinates	**coordinates;
	char			**split_result;

	fd = open(argv, O_RDONLY);
	y = 0;
	while (get_next_line(fd) != NULL)
	{
		x = 0;
		split_result = ft_split(get_next_line(fd), ' ');
		while (split_result[x] != NULL)
		{
			coordinates[x][y].x = x;
			coordinates[x][y].y = y;
			coordinates[x][y].z = ft_atoi(split_result[x]);
			x++;
		}
		y++;
		free(split_result);
	}
	close(fd);
	return (coordinates);
}
