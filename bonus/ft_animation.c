/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:55:56 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/14 15:29:51 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_find_y(t_prgrm *vars, char letter)
{
	int	y;

	y = 0;
	while (ft_strchr(vars->map[y], letter) == 0)
		y++;
	vars->pos_square_y = 32 + (y * 32);
	return (y);
}

void	ft_find_x(t_prgrm *vars, char *string, char letter)
{
	int	x;

	x = 0;
	while (string[x] != letter)
		x++;
	vars->pos_square_x = 32 + (x * 32);
	usleep(75000);
	vars->counter++;
}

int	ft_loop_player(t_prgrm *vars)
{
	int	y;

	y = 0;
	y = ft_find_y(vars, 'P');
	ft_find_x(vars, vars->map[y], 'P');
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
		ft_animate_villain_right(vars, x, y);
	else if (vars->dir_vil == 2)
		ft_animate_villain_left(vars, x, y);
	return (0);
}

int	ft_loop(t_prgrm *vars)
{
	ft_loop_player(vars);
	if (vars->villain == 1)
		ft_loop_villain(vars);
	return (0);
}
