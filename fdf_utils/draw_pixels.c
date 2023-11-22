/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:33:21 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/22 15:31:40 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	draw_pixels(t_map   *s_map, mlx_image_t *img)
{
    while (s_map != NULL)
    {
        mlx_put_pixel(img, s_map->s_coordinate->x * s_map->s_coordinate->z, s_map->s_coordinate->y * s_map->s_coordinate->z, 0xFFFFFF);
        s_map = s_map->next;
    }
	return ;
}
