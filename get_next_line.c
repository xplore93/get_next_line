/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 08:27:22 by estina            #+#    #+#             */
/*   Updated: 2019/11/11 11:34:31 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void	ft_search_nl(char *buffer, char **line)
{
	int			i;
	int			j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	*line = malloc(i + 1);
	j = 0;
	while (j < i)
	{
		printf("%c", buffer[0]);
		//(*line)[j] = buffer[j];
		printf("Estoy aqui\n");
		j++;
	}

	*line[j] = 0;
}

int			get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	int			lecture;

	if (fd < 0)
		return (-1);
	if (!(lecture = read(fd, buffer, BUFFER_SIZE)))
		return (-1);
	buffer[lecture] = 0;
	ft_search_nl(buffer, line);
	return (1);
}
