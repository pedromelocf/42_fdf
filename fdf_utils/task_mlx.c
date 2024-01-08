/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:37:00 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/08 13:33:12 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	task_mlx(mlx_t *mlx, mlx_image_t *img)
{
	mlx_key_hook(mlx, &key_hook, mlx);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return ;
}
