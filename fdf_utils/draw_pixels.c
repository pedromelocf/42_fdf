/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:33:21 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/05 12:54:29 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	draw_pixels(t_map *s_map, mlx_image_t *img)
{
	float	**map_matrix;
	float	**converted_matrix;
	int		x;
	int		width;
	int		height;

	width = s_map->width;
	height = s_map->height;
	x = 0;
	draw_background(img);
	map_matrix = get_map_matrix(s_map);
	converted_matrix = convert_matrix(s_map, map_matrix);
	while (s_map != NULL)
	{
		if (((x + 1) % width) != '0')
			draw_line(img, converted_matrix, x, x + 1);
		if (((x + 1) % height != '0'))
			draw_line(img, converted_matrix, x, x + width);
		x++;
		s_map = s_map->next;
	}
	clean_matrix(converted_matrix);
	return ;
}

void	draw_background(mlx_image_t *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			mlx_put_pixel(img, x, y, BACKGROUND_COLOR);
			x++;
		}
		x = 0;
		y++;
	}
	return ;
}

float	**get_map_matrix(t_map *s_map)
{
	float	**map_matrix;
	int		x;
	int		y;

	y = 0;
	x = 0;
	map_matrix = malloc(sizeof(float *) * (s_map->height * s_map->width + 2));
	while (s_map != NULL)
	{
		y = 0;
		map_matrix[x] = malloc(sizeof(float) * 2);
		map_matrix[x][y] = (s_map->s_coordinate->x - s_map->s_coordinate->y)
			* cos(COS_30);
		y++;
		map_matrix[x][y] = (s_map->s_coordinate->x + s_map->s_coordinate->y)
			* sin(SIN_30) - 0.3 * s_map->s_coordinate->z;
		x++;
		s_map = s_map->next;
	}
	map_matrix[x] = NULL;
	return (map_matrix);
}
