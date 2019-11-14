/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 08:27:22 by estina            #+#    #+#             */
/*   Updated: 2019/11/14 15:58:38 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	ft_freemem(char **memory)
{
	if (memory != NULL && *memory != NULL)
	{
		free(*memory);
		*memory = NULL;
	}
}

static int	ft_append(char **memory, char **line)
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
	return (1);
}

int			get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*memory[10255];
	int			lecture;
	char		*temp;

	if (BUFFER_SIZE <= 0 || fd < 0 || !line)
		return (-1);
	while ((lecture = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[lecture] = 0;
		if (!memory[fd])
			memory[fd] = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(memory[fd], buffer);
			free(memory[fd]);
			memory[fd] = temp;
		}
		if (ft_strchr(memory[fd], '\n'))
			break ;
	}
	if (lecture < 0 || (lecture == 0 && !memory[fd]))
		return (lecture);
	return (ft_append(&memory[fd], line));
}
