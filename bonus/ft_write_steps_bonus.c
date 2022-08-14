/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_steps_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:05:15 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/14 16:32:36 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_write_steps_display(t_prgrm *vars)
{
	char	*moves;
	char	*moves_2;

	if (vars->moves == 0)
		mlx_string_put(vars->mlx, vars->mlx_win, ((vars->x / 2) * 32),
			((vars->y * 32) + 64), 0xFFFFFFFF, "MOVES:");
	vars->moves++;
	moves = ft_itoa(vars->moves);
	if (vars->moves > 0)
	{
		moves_2 = ft_itoa(vars->moves - 1);
		mlx_string_put(vars->mlx, vars->mlx_win, ((vars->x / 2) * 32) + 64,
			((vars->y * 32) + 64), 0x00000000, moves_2);
		free (moves_2);
	}
	mlx_string_put(vars->mlx, vars->mlx_win, ((vars->x / 2) * 32) + 64,
		((vars->y * 32) + 64), 0xFFFFFFFF, moves);
	free (moves);
}
