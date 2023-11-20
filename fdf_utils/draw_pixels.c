/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:33:21 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/20 17:19:24 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	draw_pixels(char **map, mlx_image_t *img)
{
   int x = 0;
    int y = 0;

    while (map[y] != NULL)
    {
        x = 0;
        while (map[y][x] != '\0')
        {
            if (map[y][x] == '0')
                mlx_put_pixel(img, x * 20, y * 20, 0xFFFFFF);
            if (map[y][x] == '1')
                mlx_put_pixel(img, x * 20, y * 20, 0xFFFFFF);
            x++;
        }
        y++;
    }
	return;
}
