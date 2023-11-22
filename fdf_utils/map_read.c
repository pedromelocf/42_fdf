/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:06:23 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/11/22 16:51:29 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

t_map	*map_read(const char *argv)
{
	t_map			*s_map;
	char			*line;
	int				fd;
	int				y;

	fd = open(argv, O_RDONLY);
	y = 0;
	if (fd == -1)
	{
		perror("Error opening file");
		return(NULL);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		s_map = new_list(line, y);
		y++;
	}
	close(fd);
	return (s_map);
}
t_map	*new_list(char *line, int y)
{
	int				x;
	char			**split_result;
	t_map			*s_list;

	x = 0;
	split_result = ft_split(line, ' ');
	while (split_result[x] != NULL)
	{
		s_list = new_node(x, y, ft_atoi(split_result[x]));
		s_list = insert_nodes(s_list);
		x++;
	}
	free(split_result);
	return(s_list);
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

t_map	*insert_nodes(t_map *s_list)
{
	t_map	*head;
	t_map	*current;

	head = NULL;
	current = NULL;
	if (!s_list)
		return(NULL);
	if (head == NULL)
	{
		head = s_list;
		current = head;
	}
	if (head != NULL)
	{
		current->next = s_list;
		current = current->next;
	}
	return (head);
}
