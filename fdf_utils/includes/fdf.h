/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:19:56 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/30 12:04:06 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

#include "../../MLX42/include/MLX42/MLX42.h"
#include "../../lib/libft.h"
#include "../../lib/gnl/get_next_line.h"
#include "../../lib/printf/ft_printf.h"

#define WIDTH 800
#define HEIGHT 600

typedef	struct	s_coordinate
{
	float	x;
	float	y;
	float	z;
}	t_coordinates;

typedef struct s_map
{
	t_coordinates	*s_coordinate;
	struct s_map	*next;
	float		width;
	float		height;
}	t_map;

int		check_map_format(const char *argv);
float   **get_map_matrix(t_map *s_map);

t_map	*map_read(const char *argv);
t_map	*new_list(char *line, int y);
t_map	*new_node(int x, int y, int z);
t_map	*insert_node(t_map *head, t_map *s_list);

void	draw_pixels(t_map   *s_map, mlx_image_t *img);
void	draw_background(mlx_image_t *img);

void	clean_data(t_map	*s_map);
void	clean_split(char	**split_result);

int		map_size(t_map  *s_map);
void	key_hook(mlx_key_data_t keydata, void* mlx);

#endif
