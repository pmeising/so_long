/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:01:55 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/07 09:13:13 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// takes 2 strings and mallocs space for the combined string.
// don't forget to free the original strings if not needed further. 

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		k;
	int		len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	dest = (char *)malloc(len);
	i = 0;
	if (dest == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	k = 0;
	while (s2[k] != '\0')
	{
		dest[i + k] = s2[k];
		k++;
	}
	dest[i + k] = '\0';
	return (dest);
}
