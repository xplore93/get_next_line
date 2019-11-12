/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 08:27:22 by estina            #+#    #+#             */
/*   Updated: 2019/11/12 23:23:21 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int			get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*memory;
	int			lecture;
	int			nl;
	char		*temp;

	if (BUFFER_SIZE <= 0 || fd < 0 || !line)
		return (-1);
	if (!memory)
	{
		if (!(lecture = read(fd, buffer, BUFFER_SIZE)))
			return (-1);
		buffer[lecture] = 0;
		// Search new line
		if ((nl = ft_find_n(buffer, '\n')) == -1)
		{
			if (!*line)
			{
				*line = malloc(lecture + 1);
				ft_strlcpy(*line, buffer, lecture + 1);
			}
			else
			{
				temp = ft_strjoin(*line, buffer);
				free(*line);
				*line = temp;
			}
			printf("NOT FOUND:\n");
			printf("\tBUFFER: %s|\n", buffer);
			printf("\tSIZE: %d\n", BUFFER_SIZE);
			printf("\tLECTURE: %d\n", lecture);
			printf("\tNL: %d|\n", nl);
			printf("\tLINE: %s|\n", *line);
			printf("\tMEMORY: %s|\n", memory);
			return (get_next_line(fd, line));
		}
		// New line found
		else
		{
			*line = malloc(nl + 1);
			ft_strlcpy(*line, buffer, nl + 1);
			memory = malloc(lecture - nl);
			ft_strlcpy(memory, buffer + nl + 1, lecture);
			printf("FOUND:\n");
			printf("\tBUFFER: %s|\n", buffer);
			printf("\tSIZE: %d\n", BUFFER_SIZE);
			printf("\tLECTURE: %d\n", lecture);
			printf("\tNL: %d|\n", nl);
			printf("\tLINE: %s|\n", *line);
			printf("\tMEMORY: %s|\n", memory);
			return (1);
		}
	}
	else
	{
		printf("Memory: %s\n", memory);
		// Search new line
		if ((nl = ft_find_n(memory, '\n')) == -1)
		{
			if (!*line)
			{
				*line = malloc(ft_strlen(memory) + 1);
				ft_strlcpy(*line, memory, ft_strlen(memory) + 1);
			}
			else
			{
				temp = ft_strjoin(*line, memory);
				free(*line);
				*line = temp;
			}
			if (!(lecture = read(fd, buffer, BUFFER_SIZE)))
				return (0);
			buffer[lecture] = 0;
			temp = memory;
			free(temp);
			printf("NOT FOUND:\n");
			printf("\tNL: %d|\n", nl);
			printf("\tLINE: %s|\n", *line);
			printf("\tMEMORY: %s|\n", memory);
			return (get_next_line(fd, line));
		}
		// New line found
		else
		{
			*line = malloc(nl + 1);
			ft_strlcpy(*line, memory, nl + 1);
			temp = memory;
			memory = malloc(ft_strlen(temp) - nl);
			ft_strlcpy(memory, temp + nl + 1, ft_strlen(temp));
			free(temp);
			printf("FOUND:\n");
			printf("\tNL: %d|\n", nl);
			printf("\tLINE: %s|\n", *line);
			printf("\tMEMORY: %s|\n", memory);
			return (1);
		}
		return (-1);
	}
	return (0);
}
