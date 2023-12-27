/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix_dimensions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 19:35:23 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/12/26 19:37:10 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

t_matrix_width    *get_matrix_width(float   **map_matrix, t_map *s_map)
{
    t_matrix_width  *s_matrix_width;
    int x;
    int y;

    x = 0;
    s_matrix_width = malloc(sizeof(float) * 3);
    s_matrix_width->min_matrix_width = 0;
    s_matrix_width->max_matrix_width = 0;

    while (x < s_map->width * s_map->height)
    {
        y = 0;
        if(map_matrix[x][y] < s_matrix_width->min_matrix_width)
            s_matrix_width->min_matrix_width = map_matrix[x][y];
        if(map_matrix[x][y] > s_matrix_width->max_matrix_width)
            s_matrix_width->max_matrix_width = map_matrix[x][y];
        x++;
    }
    if (s_matrix_width->min_matrix_width < 0)
        s_matrix_width->matrix_width = s_matrix_width->max_matrix_width + s_matrix_width->min_matrix_width;
    else
        s_matrix_width->matrix_width = s_matrix_width->max_matrix_width - s_matrix_width->min_matrix_width;
    return(s_matrix_width);
}

t_matrix_height    *get_matrix_height(float   **map_matrix, t_map *s_map)
{
    t_matrix_height  *s_matrix_height;
    int x;
    int y;

    x = 0;
    s_matrix_height = malloc(sizeof(float) * 3);
    s_matrix_height->min_matrix_height = 0;
    s_matrix_height->max_matrix_height = 0;

    while (x < s_map->height * s_map->width)
    {
        y = 1;
        if(map_matrix[x][y] < s_matrix_height->min_matrix_height)
            s_matrix_height->min_matrix_height = map_matrix[x][y];
        if(map_matrix[x][y] > s_matrix_height->max_matrix_height)
            s_matrix_height->max_matrix_height = map_matrix[x][y];
        x++;
    }
    if (s_matrix_height->min_matrix_height < 0)
        s_matrix_height->matrix_height = s_matrix_height->max_matrix_height + s_matrix_height->min_matrix_height;
    else
        s_matrix_height->matrix_height = s_matrix_height->max_matrix_height - s_matrix_height->min_matrix_height;
    return(s_matrix_height);
}

t_matrix_dimensions	*get_matrix_dimensions(float   **map_matrix, t_map *s_map)
{
	t_matrix_dimensions	*s_matrix_dimensions;
	t_matrix_height  *s_matrix_height;
	t_matrix_width  *s_matrix_width;

	s_matrix_width = get_matrix_width(map_matrix, s_map);
    s_matrix_height = get_matrix_height(map_matrix, s_map);
	s_matrix_dimensions = malloc(sizeof(float) * 2);
	s_matrix_dimensions->matrix_height = s_matrix_height->matrix_height;
	s_matrix_dimensions->matrix_width = s_matrix_width->matrix_width;
	free(s_matrix_height);
	free(s_matrix_width);
	return(s_matrix_dimensions);
}
