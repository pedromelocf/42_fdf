/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:52:06 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/05 12:40:56 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

static void	draw_vertical_line(mlx_image_t *img, float **converted_matrix,
				int start, int end);
static void	draw_horizontal_line(mlx_image_t *img, float **converted_matrix,
				int start, int end);

static void	draw_line_larger_x_axis(mlx_image_t *img, float **converted_matrix,
				int start, int end, t_data_draw_line *line_data);

static void	draw_line_larger_y_axis(mlx_image_t *img, float **converted_matrix,
				int start, int end, t_data_draw_line *line_data);

void	draw_line(mlx_image_t *img, float **converted_matrix, int start,
		int end)
{
	t_data_draw_line	*line_data;

	line_data = new_line_data(converted_matrix, start, end);
	if (line_data->dx == 0)
		draw_vertical_line(img, converted_matrix, start, end);
	else if (line_data->dy == 0)
		draw_horizontal_line(img, converted_matrix, start, end);
	else
	{
		if (line_data->dx >= line_data->dy)
			draw_line_larger_x_axis(img, converted_matrix, start, end,
					line_data);
		else
			draw_line_larger_y_axis(img, converted_matrix, start, end,
					line_data);
	}
	free(line_data);
}

static void	draw_vertical_line(mlx_image_t *img, float **converted_matrix,
		int start, int end)
{
	if ((int)converted_matrix[end][1] > converted_matrix[start][1])
	{
		while ((int)converted_matrix[start][1] != (int)converted_matrix[end][1])
		{
			mlx_put_pixel(img, (int)converted_matrix[start][0],
					(int)converted_matrix[start][1], DRAWING_COLOR);
			converted_matrix[start][1]++;
		}
	}
	else
	{
		while ((int)converted_matrix[start][1] != (int)converted_matrix[end][1])
		{
			mlx_put_pixel(img, (int)converted_matrix[start][0],
					(int)converted_matrix[start][1], DRAWING_COLOR);
			converted_matrix[start][1]--;
		}
	}
}

static void	draw_horizontal_line(mlx_image_t *img, float **converted_matrix,
		int start, int end)
{
	if ((int)converted_matrix[end][0] > (int)converted_matrix[start][0])
	{
		while ((int)converted_matrix[start][0] != (int)converted_matrix[end][0])
		{
			mlx_put_pixel(img, (int)converted_matrix[start][0],
					(int)converted_matrix[start][1], DRAWING_COLOR);
			converted_matrix[start][0]++;
		}
	}
	else
	{
		while (((int)converted_matrix[start][0] != (int)converted_matrix[end][0]))
		{
			mlx_put_pixel(img, (int)converted_matrix[start][0],
					(int)converted_matrix[start][1], DRAWING_COLOR);
			converted_matrix[start][0]--;
		}
	}
}

static void	draw_line_larger_x_axis(mlx_image_t *img, float **converted_matrix,
		int start, int end, t_data_draw_line *line_data)
{
	line_data->control = line_data->dx / 2;
	mlx_put_pixel(img, (int)converted_matrix[start][0],
			(int)converted_matrix[start][1], DRAWING_COLOR);
	while ((int)converted_matrix[start][0] != (int)converted_matrix[end][0])
	{
		converted_matrix[start][0] += line_data->inc_x;
		line_data->control -= line_data->dy;
		if (line_data->control < 0)
		{
			converted_matrix[start][1] += line_data->inc_y;
			line_data->control += line_data->dx;
		}
		mlx_put_pixel(img, (int)converted_matrix[start][0],
				(int)converted_matrix[start][1], DRAWING_COLOR);
	}
}

static void	draw_line_larger_y_axis(mlx_image_t *img, float **converted_matrix,
		int start, int end, t_data_draw_line *line_data)
{
	line_data->control = line_data->dy / 2;
	mlx_put_pixel(img, (int)converted_matrix[start][0],
			(int)converted_matrix[start][1], DRAWING_COLOR);
	while ((int)converted_matrix[start][1] != (int)converted_matrix[end][1])
	{
		converted_matrix[start][1] += line_data->inc_y;
		line_data->control -= line_data->dx;
		if (line_data->control < 0)
		{
			converted_matrix[start][0] += line_data->inc_x;
			line_data->control += line_data->dy;
		}
		mlx_put_pixel(img, (int)converted_matrix[start][0],
				(int)converted_matrix[start][1], DRAWING_COLOR);
	}
}