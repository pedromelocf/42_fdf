/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:45:56 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/18 16:08:18 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int		check_map_format(const char *argv)
{
	int map_name_len;
    const char *format;
    int format_len;
	int start_position;

	map_name_len = ft_strlen(argv);
	format = ".fdf";
	format_len = ft_strlen(format);
	if (map_name_len >= format_len)
	{
		start_position = map_name_len - format_len;
		if (ft_strncmp(argv + start_position, format, format_len) == 0)
			return (1);
	}
	return (0);
}
