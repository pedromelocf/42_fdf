/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:33:21 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/12/11 15:30:36 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void draw_pixels(t_map *s_map, mlx_image_t *img)
{
    float    **map_matrix;
    t_matrix_width  *s_matrix_width;
    t_matrix_height *s_matrix_height;
    int x = 0;
    int y = 0;
    int centrox = WIDTH / 2;
    int centroy = HEIGHT / 2;
    int scale = 30;
    float   iso_x;
    float   iso_y;

    draw_background(img);
    map_matrix = get_map_matrix(s_map);
    s_matrix_width = get_matrix_width(map_matrix, s_map);
    s_matrix_height = get_matrix_height(map_matrix, s_map);
    while (s_map != NULL)
    {
        y = 0;
        iso_x = (map_matrix[x][y] * scale) + centrox - (s_matrix_width->matrix_width / 2 * scale);
        iso_y = (map_matrix[x][y + 1] * scale) + centroy - (s_matrix_height->matrix_height / 2 * scale);
        mlx_put_pixel(img, iso_x, iso_y, 0xFFFFFF);
        x++;
        s_map = s_map->next;
    }
    clean_map_matrix(map_matrix);
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

t_matrix_width    *get_matrix_width(float   **map_matrix, t_map *s_map)
{
    t_matrix_width  *s_matrix_width;
    int x;
    int y;

    x = 0;
    s_matrix_width = malloc(sizeof(float) * 3);
    s_matrix_width->min_matrix_width = 0;
    s_matrix_width->max_matrix_width = 0;

    while (x < s_map->width * s_map->height)
    {
        y = 0;
        while (y < 1)
        {
            if(map_matrix[x][y] < s_matrix_width->min_matrix_width)
                s_matrix_width->min_matrix_width = map_matrix[x][y];
            if(map_matrix[x][y] > s_matrix_width->max_matrix_width)
                s_matrix_width->max_matrix_width = map_matrix[x][y];
            y++;
        }
        x++;
    }
    s_matrix_width->matrix_width = s_matrix_width->max_matrix_width + s_matrix_width->min_matrix_width;
    return(s_matrix_width);
}

t_matrix_height    *get_matrix_height(float   **map_matrix, t_map *s_map)
{
    t_matrix_height  *s_matrix_height;
    int x;
    int y;

    x = 0;
    s_matrix_height = malloc(sizeof(float) * 3);
    s_matrix_height->min_matrix_height = 0;
    s_matrix_height->max_matrix_height = 0;

    while (x < s_map->height * s_map->width)
    {
        y = 1;
        while (y < 2)
        {
            if(map_matrix[x][y] < s_matrix_height->min_matrix_height)
                s_matrix_height->min_matrix_height = map_matrix[x][y];
            if(map_matrix[x][y] > s_matrix_height->max_matrix_height)
                s_matrix_height->max_matrix_height = map_matrix[x][y];
            y++;
        }
        x++;
    }
    s_matrix_height->matrix_height = s_matrix_height->max_matrix_height + s_matrix_height->min_matrix_height;
    return(s_matrix_height);
}
