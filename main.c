/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 10:44:07 by estina            #+#    #+#             */
/*   Updated: 2019/11/11 13:07:04 by estina           ###   ########.fr       */
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
	result = get_next_line(fd, line);
	if (result > 0)
		printf("%s\n", *line);
	else
		printf("Error\n");
	close(fd);
}
