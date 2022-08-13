/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_villain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 20:28:45 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/13 22:16:48 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check(t_prgrm *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->map[j] && ft_strchr(vars->map[j], 'V') == 0)
		j++;
	if (j == vars->y)
		return ;
	while (i < vars->x && vars->map[j][i] && vars->map[j][i] != 'V')
		i++;
	if (vars->map[j][i] == 'V')
		vars->villain = 1;
}

void	ft_put_villain(t_prgrm *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ft_strchr(vars->map[j], 'C') == 0)
		j++;
	while (vars->map[j][i] && vars->map[j][i] != 'C')
		i++;
	if (vars->x > 7 && vars->y > 7)
	{
		if (vars->map[j][i + 1] == '1' && vars->map[j][i - 1] == '1' &&
			vars->map[j - 1][i] == '1' && vars->map[j + 1][i] == '0' &&
			vars->map[j + 1][i + 1] == '0' && vars->map[j + 1][i - 1] == '0')
			vars->map[j + 1][i - 2] = 'V';
		else
			return ;
	}
	ft_check(vars);
}
