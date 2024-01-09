/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:45:23 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/09 15:49:30 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf_bonus.h"

void	key_hook(mlx_key_data_t keydata, void *mlx)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(mlx);
	if (keydata.key == MLX_KEY_PAGE_UP && keydata.action == MLX_PRESS)
		incrementar escala;
	if (keydata.key == MLX_KEY_PAGE_DOWN && keydata.action == MLX_PRESS)
		decrementar escala;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		converter matriz;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		converter matriz;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		convertar matriz;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		converter matriz;
}
