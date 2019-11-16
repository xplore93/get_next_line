/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 08:27:22 by estina            #+#    #+#             */
/*   Updated: 2019/11/15 16:01:00 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_freemem(char **memory)
{
	if (memory != NULL && *memory != NULL)
	{
		free(*memory);
		*memory = NULL;
	}
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
	}
	else
	{
		*line = ft_strdup(*memory);
		ft_freemem(memory);
	}
	if (lecture == 0 && !*memory)
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

static int	ft_loop(char **memory, int fd, char buffer[BUFFER_SIZE + 1])
{
	int			lecture;
	char		*temp;

	lecture = 0;
	while (ft_strchr(*memory, '\n') == 0)
	{
		if ((lecture = read(fd, buffer, BUFFER_SIZE)) <= 0)
			break ;
		buffer[lecture] = 0;
		if (!*memory)
			*memory = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(*memory, buffer);
			free(*memory);
			*memory = temp;
		}
	}
	return (lecture);
}

int			get_next_line(int fd, char **line)
{
	char		*buffer;
	static char	*memory[__INT_MAX__];
	int			lecture;

	if (BUFFER_SIZE <= 0 || fd < 0 || !line)
		return (-1);
	if (!(buffer = malloc(BUFFER_SIZE + 1)))
		return (-1);
	if (memory[fd] == NULL)
	{
		if ((lecture = read(fd, buffer, BUFFER_SIZE)) >= 0)
		{
			buffer[lecture] = 0;
			memory[fd] = ft_strdup(buffer);
		}
		else
			return (lecture);
	}
	lecture = ft_loop(&memory[fd], fd, buffer);
	if (lecture < 0 || (lecture == 0 && !memory[fd]))
		return (ft_newstr(line, lecture));
	return (ft_append(&memory[fd], line, lecture));
}
