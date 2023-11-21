/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:06:23 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/21 02:02:34 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

t_coordinates	**map_read(const char *argv)
{
	int				fd;
	int				x;
	int				y;
	t_coordinates	**coordinates;
	char	**split_result;
	char	*line;

	fd = open(argv, O_RDONLY);
	y = 0;
	coordinates = (t_coordinates **)malloc(50 * sizeof(t_coordinates *));
    for (int i = 0; i < 50; i++)
    {
        coordinates[i] = (t_coordinates *)malloc(50 * sizeof(t_coordinates));
    }

	while ((line = get_next_line(fd)) != NULL)
	{
		x = 0;
		split_result = ft_split(line, ' ');
		while (split_result[x] != NULL)
		{
			coordinates[x][y].x = x;
			coordinates[x][y].y = y;
			coordinates[x][y].z = ft_atoi(split_result[x]);
			x++;
		}
		free(split_result);
		y++;
	}
	close(fd);
	return (coordinates);
}
