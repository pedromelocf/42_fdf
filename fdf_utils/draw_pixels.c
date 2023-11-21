/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:33:21 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/21 02:04:20 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	draw_pixels(t_coordinates **coordinates, mlx_image_t *img)
{
    int x = 0;
    int y = 0;

    while (y < 18)
    {
        x = 0;
        while (coordinates[x][y].x != -1 && (x < 45))
        {
            mlx_put_pixel(img, coordinates[y][x].x * 30, coordinates[y][x].y * 30, 0xFFFFFF);
            mlx_put_pixel(img, coordinates[y][x].x * coordinates[y][x].z * 3.2, coordinates[y][x].y *coordinates[y][x].z * 3.2, 0xAAAAAA);
            x++;
        }
        y++;
    }
	return ;
}
