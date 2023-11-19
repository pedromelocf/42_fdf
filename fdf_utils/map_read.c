/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:06:23 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/18 21:03:19 by pmelo-ca         ###   ########.fr       */
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
	test = ft_split(map, ' ');
	for (int i = 0; test[i] != NULL; i++) {
        ft_printf("%s\n", test[i]);
	}
	close(fd);
	return (test);
}