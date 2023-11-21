/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:33:21 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/20 22:23:33 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	draw_pixels(t_coordinates **coordinates, mlx_image_t *img)
{
    int x = 0;
    int y = 0;

    while (coordinates[y] != NULL)
    {
        x = 0;
        while (coordinates[y][x].x != -1)
        {
            mlx_put_pixel(img, coordinates[y][x].x * coordinates[y][x].z, coordinates[y][x].y * coordinates[y][x].z, 0xFFFFFF);
            x++;
        }
        y++;
    }
	return ;
}
