/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:19:56 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/22 14:56:37 by pmelo-ca         ###   ########.fr       */
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
}	t_coordinates;

typedef struct s_map
{
	t_coordinates	*s_coordinate;
	struct s_map	*next;
}	t_map;

int		check_map_format(const char *argv);
t_map	*map_read(const char *argv);
t_map	*new_node(int x, int y, int z);;
void	draw_pixels(t_map   *s_map, mlx_image_t *img);

#endif
