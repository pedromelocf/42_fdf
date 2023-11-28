/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:45:23 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/28 15:05:23 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	key_hook(mlx_key_data_t keydata, void* param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS && param == NULL)
		puts("Testing");
}
