/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_func_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 09:53:09 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/07 09:30:28 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// Takes an unsigned long (could be int, could be unsigned int) and a character
// of the group {X, x, p}.
// Converts to hexadecimal representation and writes it to the output.
// Returns the number of characters written.

static void	ft_write_hxd(int nbr)
{
	int	lower;

	lower = nbr + 87;
	write(1, &lower, 1);
}

static void	ft_putnbr_hxd(unsigned long n)
{
	int	nbr;
	int	ch;

	nbr = n % 16;
	ch = nbr + 48;
	if (n >= 16)
	{
		n = n / 16;
		if (n > 0)
			ft_putnbr_hxd(n);
	}
	if (nbr >= 10)
	{
		ft_write_hxd(nbr);
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

int	ft_hex_func_p(unsigned long n)
{
	unsigned long	count;

	if (n == 0)
	{
		write(1, "0x0", 3);
		count = 3;
		return (count);
	}
	write(1, "0x", 2);
	count = 2;
	count += ft_count(n);
	ft_putnbr_hxd(n);
	return (count);
}
