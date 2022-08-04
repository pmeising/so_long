/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:36:20 by pmeising          #+#    #+#             */
/*   Updated: 2022/06/10 12:52:08 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_calloc(size_t number, size_t size)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = malloc(number * size);
	if (dest == NULL)
		return (dest);
	while (i < (number * size))
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s || s[0] == '\0')
		return (i);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(&s[i]));
		i++;
	}
	if ((char)c == '\0' && s[i] == '\0')
		return ((char *)(&s[i]));
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	total_len;
	size_t	i;

	if (!s)
		return (NULL);
	substr = malloc(len + 1);
	if (substr == 0)
		return (NULL);
	total_len = start + len;
	i = 0;
	while (start < total_len)
	{
		substr[i] = s[start];
		start++;
		i++;
	}
	substr[i] = 0;
	return (substr);
}

int	ft_len(char *remainder)
{
	int	i;

	i = 0;
	if (ft_strchr(remainder, '\n') != NULL)
	{
		while (remainder[i] != '\n')
			i++;
		return (i + 1);
	}
	else
	{
		while (remainder[i] != '\0')
			i++;
		return (i + 1);
	}
	return (0);
}
