/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:11:00 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/18 15:13:19 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int main(int argc, char **argv)
{
	mlx_t*	mlx;
	mlx_image_t* img;

	if (argc != 2 || check_map_format(argv[1]) == 0)
		return(printf("%s", "error"));
	else
	{
		mlx = mlx_init(500, 500, "FDF", true);
		img = mlx_new_image(mlx, 500, 500);
		if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
			return(printf("%s", "error"));
		mlx_put_pixel(img, 0, 0, 0xFF0000FF);
		mlx_put_pixel(img, 250, 250, 0xFF0000FF);
		mlx_loop(mlx);
		ft_printf("Heel %s", argv[1]);
	}
	return (0);
}
