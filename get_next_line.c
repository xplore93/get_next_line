/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 08:27:22 by estina            #+#    #+#             */
/*   Updated: 2019/11/11 13:22:10 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void	ft_search_nl(char *buffer, char **line)
{
	int			i;
	int			j;
	char		*aux;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!(aux = malloc(i + 1)))
		return ;
	j = 0;
	while (j < i)
	{
		aux[j] = buffer++;
		j++;
	}
	if (*buffer == '\n')
		buffer++;
	aux[j] = 0;
	*line = aux;
}

int			get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*mem;
	int			lecture;

	mem = NULL;
	if (!mem)
	{
		if (fd < 0 || !line)
			return (-1);
		if (!(lecture = read(fd, buffer, BUFFER_SIZE)))
			return (-1);
		buffer[lecture] = 0;
		ft_search_nl(buffer, line);
		mem = ft_strcpy(mem, buffer);
		return (1);
	}
}
