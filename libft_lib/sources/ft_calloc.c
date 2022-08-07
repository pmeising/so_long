/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:40:33 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/07 09:13:13 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
