/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:45:56 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/18 03:46:19 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int		check_map_format(const char argv[1])
{
	int map_name_len;

	map_name_len = ft_strlen(argv);
	if (ft_strnstr(argv, ".fdf", map_name_len))
		return(0);
	return(1);

}
