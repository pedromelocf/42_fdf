/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:50:13 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/09 12:19:45 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

t_data_draw_line	*new_line_data(mlx_image_t *img, float **converted_matrix,
		int start, int end)
{
	t_data_draw_line	*line_data;

	line_data = malloc(sizeof(t_data_draw_line));
	line_data->img = img;
	line_data->dx = ft_abs(converted_matrix[end][0]
			- converted_matrix[start][0]);
	line_data->dy = ft_abs(converted_matrix[end][1]
			- converted_matrix[start][1]);
	line_data->control = 0;
	if (converted_matrix[end][0] > converted_matrix[start][0])
		line_data->inc_x = 1;
	else
		line_data->inc_x = -1;
	if (converted_matrix[end][1] > converted_matrix[start][1])
		line_data->inc_y = 1;
	else
		line_data->inc_y = -1;
	return (line_data);
}

void	draw_background(mlx_image_t *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		while (x < SCREEN_WIDTH)
		{
			mlx_put_pixel(img, x, y, BACKGROUND_COLOR);
			x++;
		}
		x = 0;
		y++;
	}
	return ;
}

void	put_pixel(mlx_image_t *img, int start, int end, int color)
{
	if (start <= 0 || end <= 0 || start >= SCREEN_WIDTH || end >= SCREEN_HEIGHT)
		return ;
	mlx_put_pixel(img, start, end, color);
}