/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 10:44:07 by estina            #+#    #+#             */
/*   Updated: 2019/11/13 03:41:17 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	char	**line;
	int		fd;
	int		result;

	line = malloc(2);
	line[1] = NULL;
	if (argc > 1)
		fd = open(argv[1], O_RDONLY);
	else
		fd = 0;
	while ((result = get_next_line(fd, line)) >= 0)
	{
		if (result == 1)
			printf("%s\n", *line);
		else if (result == -1)
		{
			printf("Error\n");
			return (0);
		}
		else
			return (0);
	}
	free(*line);
	free(line);
	close(fd);
}
