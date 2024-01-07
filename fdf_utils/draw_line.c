/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:52:06 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/07 01:15:43 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

static void	draw_vertical_line(t_data_draw_line *line_data, float **converted_matrix,
				int start, int end);
static void	draw_horizontal_line(t_data_draw_line *line_data, float **converted_matrix,
				int start, int end);

static void	draw_line_larger_x_axis(t_data_draw_line *line_data, float **converted_matrix,
				int start, int end);

static void	draw_line_larger_y_axis(t_data_draw_line *line_data, float **converted_matrix,
				int start, int end);

void	draw_line(mlx_image_t *img, float **converted_matrix, int start,
		int end)
{
	t_data_draw_line	*line_data;

	line_data = new_line_data(img, converted_matrix, start, end);
	if (line_data->dx == 0)
		draw_vertical_line(line_data, converted_matrix, start, end);
	else if (line_data->dy == 0)
		draw_horizontal_line(line_data, converted_matrix, start, end);
	else
	{
		if (line_data->dx >= line_data->dy)
			draw_line_larger_x_axis(line_data, converted_matrix, start, end);
		else
			draw_line_larger_y_axis(line_data, converted_matrix, start, end);
	}
	free(line_data);
}

static void	draw_vertical_line(t_data_draw_line *line_data, float **converted_matrix,
		int start, int end)
{
	int	x;

	x = 0;
	if ((int)converted_matrix[end][1] > converted_matrix[start][1])
	{
		while ((int)converted_matrix[start][1] != (int)converted_matrix[end][1])
		{
			mlx_put_pixel(line_data->img, (int)converted_matrix[start][0],
				(int)converted_matrix[start][1], DRAWING_COLOR);
			converted_matrix[start][1]++;
			x++;
		}
	}
	else
	{
		while ((int)converted_matrix[start][1] != (int)converted_matrix[end][1])
		{
			mlx_put_pixel(line_data->img, (int)converted_matrix[start][0],
				(int)converted_matrix[start][1], DRAWING_COLOR);
			converted_matrix[start][1]--;
			x--;
		}
	}
	converted_matrix[start][1] -= x;
}

static void	draw_horizontal_line(t_data_draw_line *line_data, float **converted_matrix,
		int start, int end)
{
	int	x;

	x = 0;
	if ((int)converted_matrix[end][0] > (int)converted_matrix[start][0])
	{
		while ((int)converted_matrix[start][0] != (int)converted_matrix[end][0])
		{
			mlx_put_pixel(line_data->img, (int)converted_matrix[start][0],
				(int)converted_matrix[start][1], DRAWING_COLOR);
			converted_matrix[start][0]++;
			x++;
		}
	}
	else
	{
		while ((int)converted_matrix[start][0] != (int)converted_matrix[end][0])
		{
			mlx_put_pixel(line_data->img, (int)converted_matrix[start][0],
				(int)converted_matrix[start][1], DRAWING_COLOR);
			converted_matrix[start][0]--;
			x--;
		}
	}
	converted_matrix[start][0] -= x;
}

static void	draw_line_larger_x_axis(t_data_draw_line *line_data, float **converted_matrix,
		int start, int end)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	line_data->control = line_data->dx / 2;
	mlx_put_pixel(line_data->img, (int)converted_matrix[start][0],
		(int)converted_matrix[start][1], DRAWING_COLOR);
	while ((int)converted_matrix[start][0] != (int)converted_matrix[end][0])
	{
		converted_matrix[start][0] += line_data->inc_x;
		x += line_data->inc_x;
		line_data->control -= line_data->dy;
		if (line_data->control < 0)
		{
			converted_matrix[start][1] += line_data->inc_y;
			y += line_data->inc_y;
			line_data->control += line_data->dx;
		}
		mlx_put_pixel(line_data->img, (int)converted_matrix[start][0],
			(int)converted_matrix[start][1], DRAWING_COLOR);
	}
	converted_matrix[start][0] -= x;
	converted_matrix[start][1] -= y;
}

static void	draw_line_larger_y_axis(t_data_draw_line *line_data, float **converted_matrix,
		int start, int end)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	line_data->control = line_data->dy / 2;
	mlx_put_pixel(line_data->img, (int)converted_matrix[start][0],
		(int)converted_matrix[start][1], DRAWING_COLOR);
	while ((int)converted_matrix[start][1] != (int)converted_matrix[end][1])
	{
		converted_matrix[start][1] += line_data->inc_y;
		y += line_data->inc_y;
		line_data->control -= line_data->dx;
		if (line_data->control < 0)
		{
			converted_matrix[start][0] += line_data->inc_x;
			x += line_data->inc_x;
			line_data->control += line_data->dy;
		}
		mlx_put_pixel(line_data->img, (int)converted_matrix[start][0],
			(int)converted_matrix[start][1], DRAWING_COLOR);
	}
	converted_matrix[start][0] -= x;
	converted_matrix[start][1] -= y;
}
