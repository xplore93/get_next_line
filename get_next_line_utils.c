/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 08:27:34 by estina            #+#    #+#             */
/*   Updated: 2019/11/12 21:11:26 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_find_n(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] >= 0)
	{
		if (s[i] == c)
			return (i);
		if (!s[i] && s[i] == c)
			return (i);
		if (!s[i])
			break ;
		i++;
	}
	return (-1);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char *aux;
	char *s;

	if (!dst)
		return (dstsize);
	aux = dst + dstsize;
	s = (char*)src;
	while (*s && dst < aux)
		*dst++ = *s++;
	if (dst < aux)
		*dst = 0;
	else if (dstsize > 0)
		dst[-1] = 0;
	while (*s)
		s++;
	return (s - src);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(str = malloc(i + j + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = 0;
	return (str);
}
