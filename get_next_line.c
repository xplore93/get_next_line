/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 08:27:22 by estina            #+#    #+#             */
/*   Updated: 2019/11/13 16:23:01 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_find_n(char *dst, char *src)
{
	char		*nl;
	char		*temp;

	if ((nl = ft_strchr(src, '\n')))
		*nl = 0;
	else
		nl = src;
	temp = dst;
	dst = ft_strjoin(dst, src);
	free(dst);
	temp = src;
	src = ft_strdup(++nl);
	free(src);
	return (dst);
}

int			get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*memory;
	int			lecture;
	char		*nl;
	char		*temp;

	if (BUFFER_SIZE <= 0 || fd < 0 || !line)
		return (-1);
	if (memory)
		*line = ft_find_n(*line, memory);
	else
	{
		if ((lecture = read(fd, buffer, BUFFER_SIZE)) <= 0)
			return (lecture);
		buffer[lecture] = 0;
		memory = ft_strdup(buffer);
		*line = ft_find_n(*line, memory);
	}
	return (1);
}
