/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:38:59 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/12/22 20:00:04 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

float	**convert_matrix(t_map *s_map, float **map_matrix)
{
	float **converted_matrix;
	t_matrix_dimensions	*s_matrix_dimensions;
	int x = 0;
	int y = 0;
    int scale = 30;

	s_matrix_dimensions = get_matrix_dimensions(map_matrix, s_map);
	converted_matrix = malloc(sizeof(float *) * (s_map->height * s_map->width + 2));
	while (s_map != NULL)
	{
		y = 0;
		converted_matrix[x] = malloc(sizeof(float) * 2);
        converted_matrix[x][y] = (map_matrix[x][y] * scale) + (WIDTH / 2) - (s_matrix_dimensions->matrix_width / 2 * scale);
        converted_matrix[x][y + 1] = (map_matrix[x][y + 1] * scale) + (HEIGHT / 2) - (s_matrix_dimensions->matrix_height / 2 * scale);
        x++;
        s_map = s_map->next;
	}
	clean_map_matrix(map_matrix);
	free(s_matrix_dimensions);
	return (converted_matrix);
}
