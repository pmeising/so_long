/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:55:56 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/13 21:54:10 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_left_over(t_prgrm *vars)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (vars->map[y] && ft_strchr(vars->map[y], 'V') == 0)
		y++;
	while (x < vars->x && vars->map[y][x] != 'V')
		x++;
	vars->pos_square_x = 32 + (x * 32);
	vars->pos_square_y = 32 + (y * 32);
	ft_put_square(vars, 0);
}

int	ft_loop_player(t_prgrm *vars)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (ft_strchr(vars->map[y], 'P') == 0)
		y++;
	while (vars->map[y][x] != 'P')
		x++;
	vars->pos_square_x = 32 + (x * 32);
	vars->pos_square_y = 32 + (y * 32);
	usleep(75000);
	vars->counter++;
	if (vars->animate == 1 && vars->dir == 1)
	{
		if (vars->counter == 8)
			vars->counter = 0;
		ft_put_square_loop(vars, vars->counter);
	}
	else if (vars->animate == 1 && vars->dir == 2)
	{
		if (vars->counter == 8)
			vars->counter = 0;
		ft_put_square_loop(vars, vars->counter + 8);
	}
	return (0);
}

int	ft_loop_villain(t_prgrm *vars)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (vars->map[y] && ft_strchr(vars->map[y], 'V') == 0)
		y++;
	while (x < vars->x && vars->map[y][x] != 'V')
		x++;
	vars->pos_square_x = 32 + (x * 32);
	vars->pos_square_y = 32 + (y * 32);
	usleep(10000);
	vars->counter_vil++;
	if (vars->dir_vil == 1)
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
	else if (vars->dir_vil == 2)
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
	return (0);
}

int	ft_loop(t_prgrm *vars)
{
	ft_loop_player(vars);
	if (vars->villain == 1)
		ft_loop_villain(vars);
	return (0);
}
