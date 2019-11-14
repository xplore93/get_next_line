/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 08:27:22 by estina            #+#    #+#             */
/*   Updated: 2019/11/14 22:22:03 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void	ft_freemem(char **memory)
{
	free(*memory);
	*memory = NULL;
}

static int	ft_append(char **memory, char **line, int lecture)
{
	int		len;
	char	*temp;

	len = 0;
	while ((*memory)[len] != '\n' && (*memory)[len])
		len++;
	if ((*memory)[len] == '\n')
	{
		*line = ft_substr(*memory, 0, len);
		temp = ft_strdup(&((*memory)[len + 1]));
		free(*memory);
		*memory = temp;
		if ((*memory)[0] == 0)
			ft_freemem(memory);
	}
	else
	{
		*line = ft_strdup(*memory);
		ft_freemem(memory);
	}
	if (lecture == 0)
		return (0);
	return (1);
}

static int	ft_newstr(char **line, int lecture)
{
	char		*aux;

	aux = malloc(1);
	aux[0] = 0;
	*line = aux;
	return (lecture);
}

int			get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*memory;
	int			lecture;
	char		*temp;

	if (BUFFER_SIZE <= 0 || fd < 0 || !line)
		return (-1);
	while ((lecture = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[lecture] = 0;
		if (!memory)
			memory = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(memory, buffer);
			free(memory);
			memory = temp;
		}
		if (ft_strchr(memory, '\n'))
			break ;
	}
	if (lecture < 0 || (lecture == 0 && !memory))
		return (ft_newstr(line, lecture));
	return (ft_append(&memory, line, lecture));
}
