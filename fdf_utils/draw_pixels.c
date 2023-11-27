/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:33:21 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/27 13:59:15 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

#include <math.h>

void draw_pixels(t_map *s_map, mlx_image_t *img)
{
    int     scale;
    float   x_iso;
    float   y_iso;

    draw_background(img);
    scale = map_size(s_map);
    while (s_map != NULL)
    {
        x_iso = (s_map->s_coordinate->x - s_map->s_coordinate->y) * cos(0.86602540378);
        y_iso = (s_map->s_coordinate->x + s_map->s_coordinate->y) * sin(0.5) - s_map->s_coordinate->z;
        mlx_put_pixel(img, ((x_iso + 15) * scale), ((y_iso + 10) * scale), 0xFFF222);
        s_map = s_map->next;
    }
    return;
}

void    draw_background(mlx_image_t *img)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < HEIGHT)
    {
        while (x < WIDTH)
        {
            mlx_put_pixel(img, x, y, 0x000ddd);
            x++;
        }
        x = 0;
        y++;
    }
    return;
}

int    map_size(t_map  *s_map)
{
    int     x;
    int     scale;

    while (s_map != NULL)
    {
        s_map = s_map->next;
        x++;
    }
    if (x < 1000)
        scale = 20;
    if (x > 1000)
        scale = 1.5;
    return (scale);
}
