/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:11:00 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/09 15:47:29 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf_bonus.h"

int	main(int argc, char **argv)
{
	t_map		*s_map;
	mlx_t		*mlx;
	mlx_image_t	*img;

	if (argc != 2 || !(check_map_format(argv[1])))
		return (ft_printf("%s", "Invalid map name"));
	s_map = map_read(argv[1]);
	mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "FDF", true);
	img = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx_image_to_window(mlx, img, 0, 0);
	s_map->converted_matrix = render(s_map, img);
	task_mlx(mlx);
	free(s_map->converted_matrix);
	clean_data(s_map);
	return (1);
}
