/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 10:44:07 by estina            #+#    #+#             */
/*   Updated: 2019/11/12 23:31:44 by estina           ###   ########.fr       */
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

	line = malloc(1);
	if (argc > 1)
		fd = open(argv[1], O_RDONLY);
	else
		fd = 0;
	while ((result = get_next_line(fd, line)) >= 0)
	{
		if (result > 0)
			printf("%s\n", *line);
		else
		{
			printf("Error\n");
			return (0);
		}
	}
	close(fd);
}
