/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 07:44:39 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/07 09:34:19 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// Takes a string to print out to the terminal. 
// Returns the count of characters printed out.

int	ft_putstr(char *s)
{
	int	i;
	int	count;

	count = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		count = 6;
		return (6);
	}
	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
		count++;
	}
	return (count);
}
