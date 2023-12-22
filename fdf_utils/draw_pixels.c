/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:33:21 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/12/22 20:01:38 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void draw_pixels(t_map *s_map, mlx_image_t *img)
{
    float   **map_matrix;
    float   **converted_matrix;
    int x = 0;
    int y = 0;

    draw_background(img);
    map_matrix = get_map_matrix(s_map);
    converted_matrix = convert_matrix(s_map, map_matrix);
    while(s_map != NULL)
    {
        y = 0;
        mlx_put_pixel(img, converted_matrix[x][y], converted_matrix[x][y + 1], 0xFFFFFF);
        x++;
        s_map = s_map->next;
    }
    clean_map_matrix(converted_matrix);
    return ;
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

float    **get_map_matrix(t_map *s_map)
{
    float    **map_matrix;
    int     x;
    int     y;

    y = 0;
    x = 0;
    map_matrix = malloc(sizeof(float *) * (s_map->height * s_map->width + 2));
    while (s_map != NULL)
    {
        y = 0;
        map_matrix[x] = malloc(sizeof(float) * 2);
        map_matrix[x][y] = (s_map->s_coordinate->x - s_map->s_coordinate->y) * 0.707106781;
        y++;
        map_matrix[x][y] = ((s_map->s_coordinate->x + s_map->s_coordinate->y) * 0.40824829) - 0.816496581 * s_map->s_coordinate->z;
        x++;
        s_map = s_map->next;
    }
    map_matrix[x] = NULL;
    return(map_matrix);
}
