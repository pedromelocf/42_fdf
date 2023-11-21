/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:19:56 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/20 19:25:57 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

#include "../../MLX42/include/MLX42/MLX42.h"
#include "../../lib/libft.h"
#include "../../lib/gnl/get_next_line.h"
#include "../../lib/printf/ft_printf.h"

typedef	struct	s_coordinate
{
	int	x;
	int	y;
	int	z;
}				t_coordinates;

int		check_map_format(const char *argv);
t_coordinates		**map_read(const char *argv);
void	draw_pixels(t_coordinates **map, mlx_image_t *img);

#endif
