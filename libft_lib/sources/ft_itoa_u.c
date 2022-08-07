/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:54:53 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/07 09:30:27 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// takes a numerical input, interprets it as unsigned int and converts it to
// its' Ascii representation.
// Returns a string.

static char	*ft_zero_case(int n)
{
	char	*str;

	str = malloc(2);
	if (!str)
		return (NULL);
	str[n] = 48;
	str[1] = '\0';
	return (str);
}

static int	ft_alen_u(unsigned int n)
{
	int	j;

	j = 0;
	while (n != 0)
	{
		n = n / 10;
		j++;
	}
	return (j);
}

static char	*ft_logic_u(char *str, unsigned int m, int j, int i)
{
	while (j >= 0)
	{
		str[j] = ((char )((m % 10)) + 48);
		m = m / 10;
		j--;
	}
	if (i < 0)
		str[0] = '-';
	return (str);
}

char	*ft_itoa_u(unsigned int n)
{
	char			*str;
	int				i;
	int				j;
	unsigned int	m;

	i = 0;
	j = 0;
	m = n;
	if (n == 0)
		return (ft_zero_case(n));
	j = ft_alen_u(n);
	str = malloc(1 * (j + 1));
	if (!str)
		return (NULL);
	str[j] = '\0';
	j--;
	str = ft_logic_u(str, m, j, i);
	return (str);
}
