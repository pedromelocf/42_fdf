/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:06:23 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/22 15:25:34 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

t_map	*map_read(const char *argv)
{
	t_map			*head;
	t_map			*current;
	t_map			*s_map;
	char			**split_result;
	char			*line;
	int				fd;
	int				x;
	int				y;

	fd = open(argv, O_RDONLY);
	y = 0;
	head = NULL;
	current = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		x = 0;
		split_result = ft_split(line, ' ');
		while (split_result[x] != NULL)
		{
			s_map = new_node(x, y, ft_atoi(split_result[x]));
			if (!s_map)
				return(NULL);
			if (head == NULL)
			{
				head = s_map;
				current = head;
			}
			if (head != NULL)
			{
				current->next = s_map;
				current = current->next;
			}
			x++;
		}
		free(split_result);
		y++;
	}
	close(fd);
	return (head);
}

t_map	*new_node(int x, int y, int z)
{
	t_map	*node;

	node = malloc(sizeof(t_map));
	if (!node)
		return (NULL);
	node->s_coordinate = malloc(sizeof(t_coordinates));
	if(!node->s_coordinate)
	{
		free(node);
		return(NULL);
	}
	node->s_coordinate->x = x;
	node->s_coordinate->y = y;
	node->s_coordinate->z = z;
	node->next = NULL;

	return(node);
}
