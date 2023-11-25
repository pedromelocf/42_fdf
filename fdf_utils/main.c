/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:11:00 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/25 17:32:39 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int main(int argc, char **argv)
{
	t_map	*s_map;
	mlx_t	*mlx;
	mlx_image_t	*img;

	if (argc != 2 || !(check_map_format(argv[1])))
		return(printf("%s", "error"));
	s_map = map_read(argv[1]);
	mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) == -1))
		return(printf("%s", "error"));
	draw_pixels(s_map, img);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	clean_data(s_map);
	return (1);
}
