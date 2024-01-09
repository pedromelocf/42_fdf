/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:04:44 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/09 14:25:05 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "../libft.h"

char	*ft_join_buf(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*ft_strchr_gnl(const char *s, int c);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
