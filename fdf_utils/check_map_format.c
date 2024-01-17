/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:45:56 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/17 16:19:51 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

static int	validate_file(const char *argv);

int	check_map_format(const char *argv)
{
	int			map_name_len;
	const char	*format;
	int			format_len;
	int			start_position;

	map_name_len = ft_strlen(argv);
	format = ".fdf";
	format_len = ft_strlen(format);
	if (map_name_len >= format_len)
	{
		start_position = map_name_len - format_len;
		if (!(ft_strncmp(argv + start_position, format, format_len)))
		{
			if (!(validate_file(argv)))
				return (0);
		}
	}
	return (1);
}

static int	validate_file(const char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	return (0);
}
