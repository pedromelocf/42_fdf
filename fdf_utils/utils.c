/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:50:13 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/05 12:04:57 by pmelo-ca         ###   ########.fr       */
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
								int start,
								int end)
{
	t_data_draw_line	*line_data;

	line_data = malloc(sizeof(t_data_draw_line));
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
