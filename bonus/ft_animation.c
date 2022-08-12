/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:55:56 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/12 21:07:18 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	usleep(100000);
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
	while (ft_strchr(vars->map[y], 'V') == 0)
		y++;
	while (vars->map[y][x] != 'V')
		x++;
	vars->pos_square_x = 32 + (x * 32);
	vars->pos_square_y = 32 + (y * 32);
	usleep(100000);
	if (vars->animate == 1 && vars->dir_vil == 1)
		ft_walk_villain_right(vars);
	else if (vars->animate == 1 && vars->dir_vil == 2)
		ft_walk_villain_left(vars);
	return (0);
}

int	ft_loop(t_prgrm *vars)
{
	ft_loop_player(vars);
	ft_loop_villain(vars);
	return (0);
}
	