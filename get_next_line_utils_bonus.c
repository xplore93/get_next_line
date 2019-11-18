/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 08:27:34 by estina            #+#    #+#             */
/*   Updated: 2019/11/17 18:54:31 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s >= 0)
	{
		if (*s == c)
			return ((char*)s);
		if (!*s && *s == c)
			return ((char*)s);
		if (!*s)
			break ;
		s++;
	}
	return (0);
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

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		count;

	count = 0;
	while (s1[count])
		count++;
	if (!(s2 = malloc(count + 1)))
		return (NULL);
	while (count >= 0)
	{
		s2[count] = s1[count];
		count--;
	}
	return (s2);
}
