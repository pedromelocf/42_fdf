/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:38:59 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/02 14:54:56 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

float	**convert_matrix(t_map *s_map, float **map_matrix)
{
	float				**converted_matrix;
	t_matrix_dimensions	*s_matrix_dimensions;

	s_matrix_dimensions = get_matrix_dimensions(map_matrix, s_map);
	get_map_scale(s_map, s_matrix_dimensions);
	converted_matrix = scale_dimension_matrix(s_map, map_matrix,
			s_matrix_dimensions);
	return (converted_matrix);
}

void	get_map_scale(t_map *s_map, t_matrix_dimensions *s_matrix_dimensions)
{
	float	bigger;

	if (s_matrix_dimensions->matrix_height > s_matrix_dimensions->matrix_width)
		bigger = s_matrix_dimensions->matrix_height;
	else
		bigger = s_matrix_dimensions->matrix_width;
	if (bigger > 0 && bigger <= 10)
		s_map->scale = 20;
	if (bigger > 10 && bigger <= 20)
		s_map->scale = 30;
	if (bigger > 20 && bigger <= 80)
		s_map->scale = 20;
	if (bigger > 80 && bigger <= 150)
		s_map->scale = 5;
	if (bigger > 150 && bigger <= 200)
		s_map->scale = 2.5;
	if (bigger > 200 && bigger <= 500)
		s_map->scale = 1.5;
	if (bigger > 500)
		s_map->scale = 0.7;
	return ;
}

float	**scale_dimension_matrix(t_map *s_map, float **map_matrix,
		t_matrix_dimensions *s_matrix_dimensions)
{
	int		x;
	int		y;
	float	scale;
	float	**converted_matrix;

	x = 0;
	scale = s_map->scale;
	converted_matrix = malloc(sizeof(float *) * (s_map->height * s_map->width
				+ 2));
	while (s_map != NULL)
	{
		y = 0;
		converted_matrix[x] = malloc(sizeof(float) * 2);
		converted_matrix[x][y] = (map_matrix[x][y] * scale) + (WIDTH / 2)
			- (s_matrix_dimensions->matrix_width / 2 * scale);
		converted_matrix[x][y + 1] = (map_matrix[x][y + 1] * scale) + (HEIGHT
				/ 2) - (s_matrix_dimensions->matrix_height / 2 * scale);
		x++;
		s_map = s_map->next;
	}
	converted_matrix[x] = NULL;
	clean_matrix(map_matrix);
	free(s_matrix_dimensions);
	return (converted_matrix);
}
