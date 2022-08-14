/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animate_villain.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:25:50 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/14 15:28:05 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_animate_villain_right(t_prgrm *vars, int x, int y)
{
	if (vars->counter_vil == 7)
	{
		vars->map[y][x] = '0';
		if (vars->map[y][x + 1] == 'P')
			ft_error(vars, 5);
		vars->map[y][x + 1] = 'V';
		vars->counter_vil = 0;
		ft_check_left_over(vars);
		vars->steps++;
		if (vars->steps == 4)
		{
			if (vars->dir_vil == 1)
				vars->dir_vil = 2;
			else if (vars->dir_vil == 2)
				vars->dir_vil = 1;
			vars->steps = 0;
		}
	}
	ft_put_square(vars, 0);
	vars->pos_square_x = vars->pos_square_x + (vars->counter_vil * 4);
	if (vars->counter_vil == 6)
		vars->pos_square_x = vars->pos_square_x + 8;
	ft_put_square_walk_right_villain(vars, vars->counter_vil);
}

void	ft_animate_villain_left(t_prgrm *vars, int x, int y)
{
	if (vars->counter_vil == 7)
	{
		vars->map[y][x] = '0';
		if (vars->map[y][x - 1] == 'P')
			ft_error(vars, 5);
		vars->map[y][x - 1] = 'V';
		vars->counter_vil = 0;
		ft_check_left_over(vars);
		vars->steps++;
		if (vars->steps == 4)
		{
			if (vars->dir_vil == 1)
				vars->dir_vil = 2;
			else if (vars->dir_vil == 2)
				vars->dir_vil = 1;
			vars->steps = 0;
		}
	}
	ft_put_square(vars, 0);
	vars->pos_square_x = vars->pos_square_x - (vars->counter_vil * 4);
	if (vars->counter_vil == 6)
		vars->pos_square_x = vars->pos_square_x - 8;
	ft_put_square_walk_left_villain(vars, vars->counter_vil);
}
