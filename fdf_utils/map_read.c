/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:06:23 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/20 17:07:39 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

char		**map_read(const char *argv)
{
	int		fd;
	char	map[154545];
	int		bytesread;
	char	**test;

	fd = open(argv, O_RDONLY);
	bytesread = read(fd, map, 1000);
	map[bytesread] = '\0';
	test = ft_split(map, '\n');
	close(fd);
	return (test);
}
