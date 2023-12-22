/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:19:56 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/12/22 19:55:49 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

#include "../../MLX42/include/MLX42/MLX42.h"
#include "../../lib/libft.h"
#include "../../lib/gnl/get_next_line.h"
#include "../../lib/printf/ft_printf.h"

#define WIDTH 1914
#define HEIGHT 1074

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
	int		width;
	int		height;
}	t_map;

typedef struct s_matrix_width
{
	float	matrix_width;
	float	min_matrix_width;
    float	max_matrix_width;
}	t_matrix_width;

typedef struct s_matrix_height
{
	float	matrix_height;
	float	min_matrix_height;
    float	max_matrix_height;
}	t_matrix_height;

typedef struct s_matrix_dimensions
{
	float	matrix_height;
	float	matrix_width;
}	t_matrix_dimensions;

int		check_map_format(const char *argv);
float   **get_map_matrix(t_map *s_map);
t_matrix_width    *get_matrix_width(float   **map_matrix, t_map *s_map);
t_matrix_height	*get_matrix_height(float   **map_matrix, t_map *s_map);
t_matrix_dimensions	*get_matrix_dimensions(float   **map_matrix, t_map *s_map);
float	**convert_matrix(t_map *s_map, float **map_matrix);

t_map	*map_read(const char *argv);
t_map	*new_list(char *line, int y);
t_map	*new_node(int x, int y, int z);
t_map	*insert_node(t_map *head, t_map *s_list);

void	draw_pixels(t_map   *s_map, mlx_image_t *img);
void	draw_background(mlx_image_t *img);
void	bresenham_algo(mlx_image_t *img, float **converted_matrix, int x, int y);

void	clean_data(t_map	*s_map);
void	clean_split(char	**split_result);
void	clean_map_matrix(float	**map_matrix);

void	key_hook(mlx_key_data_t keydata, void* mlx);

#endif
