/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:52:06 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/03 14:05:54 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

static void	draw_vertical_line(mlx_image_t *img, float **converted_matrix,
				int x, int y);
static void	draw_horizontal_line(mlx_image_t *img, float **converted_matrix,
				int x, int y);

static void	draw_line_larger_x_axis(mlx_image_t *img, float **converted_matrix,
				int x, int y, t_data_draw_line *line_data);

static void	draw_line_larger_y_axis(mlx_image_t *img, float **converted_matrix,
				int x, int y, t_data_draw_line *line_data);

void	draw_line(mlx_image_t *img, float **converted_matrix, int x, int y)
{
	t_data_draw_line	*line_data;

	line_data = new_line_data(converted_matrix, x, y);
	if (line_data->dx == 0)
		draw_vertical_line(img, converted_matrix, x, y);
	else if (line_data->dy == 0)
		draw_horizontal_line(img, converted_matrix, x, y);
	else
	{
		if (line_data->dx >= line_data->dy)
			draw_line_larger_x_axis(img, converted_matrix, x, y, line_data);
		else
			draw_line_larger_y_axis(img, converted_matrix, x, y, line_data);
	}
}

static void	draw_vertical_line(mlx_image_t *img, float **converted_matrix,
		int x, int y)
{
	if (converted_matrix[x + 1][y + 1] > converted_matrix[x][y + 1])
	{
		while ((int)converted_matrix[x][y + 1] != (int)converted_matrix[x + 1][y
			+ 1])
		{
			y++;
			mlx_put_pixel(img, (int)converted_matrix[x][y],
					(int)converted_matrix[x][y + 1], DRAWING_COLOR);
		}
	}
	else
	{
		while ((int)converted_matrix[x][y + 1] != (int)converted_matrix[x + 1][y
			+ 1])
		{
			y--;
			mlx_put_pixel(img, (int)converted_matrix[x][y],
					(int)converted_matrix[x][y + 1], DRAWING_COLOR);
		}
	}
}

static void	draw_horizontal_line(mlx_image_t *img, float **converted_matrix,
		int x, int y)
{
	if (converted_matrix[x + 1][y] > converted_matrix[x][y])
	{
		while ((int)converted_matrix[x][y] != converted_matrix[x + 1][y])
		{
			x++;
			mlx_put_pixel(img, (int)converted_matrix[x][y],
					(int)converted_matrix[x][y + 1], DRAWING_COLOR);
		}
	}
	else
	{
		while ((int)converted_matrix[x][y] != converted_matrix[x + 1][y])
		{
			x--;
			mlx_put_pixel(img, (int)converted_matrix[x][y],
					(int)converted_matrix[x][y + 1], DRAWING_COLOR);
		}
	}
}

static void	draw_line_larger_x_axis(mlx_image_t *img, float **converted_matrix,
		int x, int y, t_data_draw_line *line_data)
{
	line_data->control = line_data->dx / 2;
	mlx_put_pixel(img, (int)converted_matrix[x][y], (int)converted_matrix[x][y
			+ 1], DRAWING_COLOR);
	while ((int)converted_matrix[x][y] != (int)converted_matrix[x + 1][y])
	{
		converted_matrix[x][y] += line_data->inc_x;
		line_data->control -= line_data->dy;
		if (line_data->control < 0)
		{
			converted_matrix[x][y + 1] += line_data->inc_y;
			line_data->control += line_data->dx;
		}
		mlx_put_pixel(img, (int)converted_matrix[x][y],
				(int)converted_matrix[x][y + 1], DRAWING_COLOR);
	}
}

static void	draw_line_larger_y_axis(mlx_image_t *img, float **converted_matrix,
		int x, int y, t_data_draw_line *line_data)
{
	line_data->control = line_data->dy / 2;
	mlx_put_pixel(img, (int)converted_matrix[x][y], (int)converted_matrix[x][y
			+ 1], DRAWING_COLOR);
	while ((int)converted_matrix[x][y + 1] != (int)converted_matrix[x + 1][y
		+ 1])
	{
		converted_matrix[x][y + 1] += line_data->inc_y;
		line_data->control -= line_data->dx;
		if (line_data->control < 0)
		{
			converted_matrix[x][y] += line_data->inc_x;
			line_data->control += line_data->dy;
		}
		mlx_put_pixel(img, (int)converted_matrix[x][y],
				(int)converted_matrix[x][y + 1], DRAWING_COLOR);
	}
}
