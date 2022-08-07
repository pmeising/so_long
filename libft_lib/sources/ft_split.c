/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:03:15 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/07 09:13:13 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_count_str(char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((s == 0) || (s[0] == '\0'))
		return (0);
	while (s[j] != '\0')
	{
		if (s[j] != c && (j == 0 || s[j - 1] == c))
			i++;
		j++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**new;

	new = malloc(sizeof(char *) * (ft_count_str(s, c) + 1));
	if (!new || !s)
		return (NULL);
	j = 0;
	k = 0;
	while (s[j])
	{
		while (s[j] == c)
			j++;
		i = j;
		while (s[j] != c && s[j] != '\0')
			j++;
		if (i != j)
		{
			new[k] = ft_substr(s, i, (j - i));
			k++;
		}
	}
	new[k] = 0;
	return (new);
}
