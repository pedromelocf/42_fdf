/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:11:00 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/17 16:24:07 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int	main(int argc, char **argv)
{
	t_map		*s_map;
	mlx_t		*mlx;
	mlx_image_t	*img;

	if (argc != 2 || check_map_format(argv[1]))
		return (print_return("Wrong file format or file doesn`t exist", 1));
	s_map = map_read(argv[1]);
	if (!(s_map))
		return (print_return("File has no content or bad format", 1));
	mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "FDF", true);
	img = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx_image_to_window(mlx, img, 0, 0);
	render(s_map, img);
	task_mlx(mlx);
	clean_data(s_map);
	return (0);
}
