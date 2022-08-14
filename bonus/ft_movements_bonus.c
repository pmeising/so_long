/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 14:33:17 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/14 16:32:26 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_walk_left(t_prgrm *vars)
{
	int	exit;

	exit = 0;
	vars->dir = 2;
	if (vars->map[((vars->pos_square_y - 32) / 32)]
		[(((vars->pos_square_x - 32) / 32) - 1)] == 'V')
		ft_game_over(vars);
	if (vars->map[((vars->pos_square_y - 32) / 32)]
		[(((vars->pos_square_x - 32) / 32) - 1)] == '1')
		return ;
	ft_helper_0(vars);
	exit = ft_helper_4(vars);
	if (exit == 1 && vars->coins == 0)
		ft_close_program(vars, 0);
	else if (exit == 1)
		return ;
	ft_helper_8(vars);
	vars->map[((vars->pos_square_y - 32) / 32)]
	[((vars->pos_square_x - 32) / 32)] = '0';
	vars->map[((vars->pos_square_y - 32) / 32)]
	[(((vars->pos_square_x - 32) / 32) - 1)] = 'P';
	vars->pos_square_x = vars->pos_square_x - 32;
}

void	ft_walk_right(t_prgrm *vars)
{
	int	exit;

	exit = 0;
	vars->dir = 1;
	if (vars->map[((vars->pos_square_y - 32) / 32)]
		[(((vars->pos_square_x - 32) / 32) + 1)] == 'V')
		ft_game_over(vars);
	if (vars->map[((vars->pos_square_y - 32) / 32)]
		[(((vars->pos_square_x - 32) / 32) + 1)] == '1')
		return ;
	ft_helper_1(vars);
	exit = ft_helper_5(vars);
	if (exit == 1 && vars->coins == 0)
		ft_close_program(vars, 0);
	else if (exit == 1)
		return ;
	ft_helper_9(vars);
	vars->map[((vars->pos_square_y - 32) / 32)]
	[((vars->pos_square_x - 32) / 32)] = '0';
	vars->map[((vars->pos_square_y - 32) / 32)]
	[(((vars->pos_square_x - 32) / 32) + 1)] = 'P';
	vars->pos_square_x = vars->pos_square_x + 32;
}

void	ft_walk_up(t_prgrm *vars)
{
	int	exit;

	exit = 0;
	if (vars->map[(((vars->pos_square_y - 32) / 32) - 1)]
		[((vars->pos_square_x - 32) / 32)] == 'V')
		ft_game_over(vars);
	if (vars->map[(((vars->pos_square_y - 32) / 32) - 1)]
		[((vars->pos_square_x - 32) / 32)] == '1')
		return ;
	ft_helper_2(vars);
	exit = ft_helper_6(vars);
	if (exit == 1 && vars->coins == 0)
		ft_close_program(vars, 0);
	else if (exit == 1)
		return ;
	ft_helper_10(vars);
	vars->map[((vars->pos_square_y - 32) / 32)]
	[((vars->pos_square_x - 32) / 32)] = '0';
	vars->map[(((vars->pos_square_y - 32) / 32) - 1)]
	[((vars->pos_square_x - 32) / 32)] = 'P';
	vars->pos_square_y = vars->pos_square_y - 32;
}

void	ft_walk_down(t_prgrm *vars)
{
	int	exit;

	exit = 0;
	if (vars->map[(((vars->pos_square_y - 32) / 32) + 1)]
		[((vars->pos_square_x - 32) / 32)] == 'V')
		ft_game_over(vars);
	if (vars->map[(((vars->pos_square_y - 32) / 32) + 1)]
		[((vars->pos_square_x - 32) / 32)] == '1')
		return ;
	ft_helper_3(vars);
	exit = ft_helper_7(vars);
	if (exit == 1 && vars->coins == 0)
		ft_close_program(vars, 0);
	else if (exit == 1)
		return ;
	ft_helper_11(vars);
	vars->map[((vars->pos_square_y - 32) / 32)]
	[((vars->pos_square_x - 32) / 32)] = '0';
	vars->map[(((vars->pos_square_y - 32) / 32) + 1)]
	[((vars->pos_square_x - 32) / 32)] = 'P';
	vars->pos_square_y = vars->pos_square_y + 32;
}

// Here I walk through the map to find the players x and y parameters.

void	ft_walk(t_prgrm *vars, int direction)
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
	if (direction == 0)
		ft_walk_up(vars);
	else if (direction == 1)
		ft_walk_left(vars);
	else if (direction == 2)
		ft_walk_down(vars);
	else if (direction == 3)
		ft_walk_right(vars);
	ft_write_steps_display(vars);
}
