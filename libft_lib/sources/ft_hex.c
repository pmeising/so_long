/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 09:53:09 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/14 14:13:44 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// Takes an unsigned long (could be int, could be unsigned int) and a character
// of the group {X, x, p}.
// Converts to hexadecimal representation and writes it to the output.
// Returns the number of characters written.

static void	ft_write_hxd(int nbr, int c)
{
	int	upper;
	int	lower;

	upper = nbr + 55;
	lower = nbr + 87;
	if (c == 'x')
		write(1, &lower, 1);
	else if (c == 'X')
		write(1, &upper, 1);
}

static void	ft_putnbr_hxd(unsigned int n, int c)
{
	int	nbr;
	int	ch;

	nbr = n % 16;
	ch = nbr + 48;
	if (n >= 16)
	{
		n = n / 16;
		if (n > 0)
			ft_putnbr_hxd(n, c);
	}
	if (nbr >= 10 && (c == 'x' || c == 'X'))
	{
		ft_write_hxd(nbr, c);
	}
	else
	{
		ch = nbr + 48;
		write(1, &ch, 1);
	}
	return ;
}

static int	ft_count(unsigned long n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	while (n != 0)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

int	ft_hex(unsigned int n, int c)
{
	unsigned long	count;

	count = 0;
	count += ft_count(n);
	ft_putnbr_hxd(n, c);
	return (count);
}
