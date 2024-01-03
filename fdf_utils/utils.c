/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:50:13 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/03 12:28:58 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

t_data_draw_line	*new_line_data(float **converted_matrix,
								int x,
								int y)
{
	t_data_draw_line	*line_data;

	line_data = malloc(sizeof(t_data_draw_line));
	line_data->dx = ft_abs(converted_matrix[x + 1][y] - converted_matrix[x][y]);
	line_data->dy = ft_abs(converted_matrix[x + 1][y + 1]
			- converted_matrix[x][y + 1]);
	line_data->control = 0;
	if (converted_matrix[x + 1][y] > converted_matrix[x][y])
		line_data->inc_x = 1;
	else
		line_data->inc_x = -1;
	if (converted_matrix[x + 1][y + 1] > converted_matrix[x][y + 1])
		line_data->inc_y = 1;
	else
		line_data->inc_y = -1;
	return (line_data);
}
