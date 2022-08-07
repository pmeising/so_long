/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:17:41 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/07 09:13:13 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		j;
	size_t	i;
	int		dst_len;

	j = 0;
	i = 0;
	while (i < size && dst[i] != '\0')
		i++;
	dst_len = i;
	if (size == 0)
		return (ft_strlen((char *)src));
	if (size == i)
		return (size + ft_strlen((char *)src));
	while (i < size - 1 && src[j] != '\0')
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (dst_len + ft_strlen(src));
}
