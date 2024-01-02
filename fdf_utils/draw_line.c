/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:52:06 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/02 12:22:08 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	bresenham_algo(mlx_image_t *img, float **converted_matrix, int x, int y)
{
	float	dx;
	float	dy;
	float	p;
	float	z;
	float	zx;

	dx = converted_matrix[x + 1][y] - converted_matrix[x + 1][y];
	dy = converted_matrix[x + 1][y + 1] - converted_matrix[x][y + 1];
	zx = converted_matrix[x][y];
	z = converted_matrix[x][y + 1];
	p = 2 * dy - dx;
	while (zx < converted_matrix[x + 1][y])
	{
		if (p >= 0)
		{
			mlx_put_pixel(img, zx, z, 0xFFFFFF);
			z += 1;
			p = p + 2 * dy - 2 * dx;
		}
		if (p < 0)
		{
			mlx_put_pixel(img, zx, z, 0xFFFFFF);
			p = p + 2 * dy;
		}
		zx = zx + 1;
	}
	return ;
}

// void	draw_lines(float **map_matrix, mlx_image_t *img, t_matrix_width  *s_matrix_width, t_matrix_height *s_matrix_height)
// {

// }
