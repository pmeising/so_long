/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 14:33:17 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/11 15:57:50 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_walk_left(t_prgrm *vars, t_image *image)
{
	int	exit;
	int	shine;

	exit = 0;
	if (vars->map[((vars->pos_square_y - 32) / 32)]
		[(((vars->pos_square_x - 32) / 32) - 1)] == '1')
		return ;
	shine = ft_helper_0(vars, image);
	exit = ft_helper_4(vars);
	if (exit == 1 && vars->coins == 0)
		ft_close_program(vars, 0);
	else if (exit == 1)
		return ;
	ft_put_square(vars, image, 0);
	vars->map[((vars->pos_square_y - 32) / 32)]
	[((vars->pos_square_x - 32) / 32)] = '0';
	vars->map[((vars->pos_square_y - 32) / 32)]
	[(((vars->pos_square_x - 32) / 32) - 1)] = 'P';
	vars->pos_square_x = vars->pos_square_x - 32;
	if (shine == 1)
		ft_put_square(vars, image, 7);
	else
		ft_put_square(vars, image, 6);
}

void	ft_walk_right(t_prgrm *vars, t_image *image)
{
	int	exit;
	int	shine;

	exit = 0;
	if (vars->map[((vars->pos_square_y - 32) / 32)]
		[(((vars->pos_square_x - 32) / 32) + 1)] == '1')
		return ;
	shine = ft_helper_1(vars, image);
	exit = ft_helper_5(vars);
	if (exit == 1 && vars->coins == 0)
		ft_close_program(vars, 0);
	else if (exit == 1)
		return ;
	ft_put_square(vars, image, 0);
	vars->map[((vars->pos_square_y - 32) / 32)]
	[((vars->pos_square_x - 32) / 32)] = '0';
	vars->map[((vars->pos_square_y - 32) / 32)]
	[(((vars->pos_square_x - 32) / 32) + 1)] = 'P';
	vars->pos_square_x = vars->pos_square_x + 32;
	if (shine == 1)
		ft_put_square(vars, image, 5);
	else
		ft_put_square(vars, image, 4);
}

void	ft_walk_up(t_prgrm *vars, t_image *image)
{
	int	exit;
	int	shine;

	exit = 0;
	if (vars->map[(((vars->pos_square_y - 32) / 32) - 1)]
		[((vars->pos_square_x - 32) / 32)] == '1')
		return ;
	shine = ft_helper_2(vars, image);
	exit = ft_helper_6(vars);
	if (exit == 1 && vars->coins == 0)
		ft_close_program(vars, 0);
	else if (exit == 1)
		return ;
	ft_put_square(vars, image, 0);
	vars->map[((vars->pos_square_y - 32) / 32)]
	[((vars->pos_square_x - 32) / 32)] = '0';
	vars->map[(((vars->pos_square_y - 32) / 32) - 1)]
	[((vars->pos_square_x - 32) / 32)] = 'P';
	vars->pos_square_y = vars->pos_square_y - 32;
	if (shine == 1)
		ft_put_square(vars, image, 5);
	else
		ft_put_square(vars, image, 4);
}

void	ft_walk_down(t_prgrm *vars, t_image *image)
{
	int	exit;
	int	shine;

	exit = 0;
	if (vars->map[(((vars->pos_square_y - 32) / 32) + 1)]
		[((vars->pos_square_x - 32) / 32)] == '1')
		return ;
	shine = ft_helper_3(vars, image);
	exit = ft_helper_7(vars);
	if (exit == 1 && vars->coins == 0)
		ft_close_program(vars, 0);
	else if (exit == 1)
		return ;
	ft_put_square(vars, image, 0);
	vars->map[((vars->pos_square_y - 32) / 32)]
	[((vars->pos_square_x - 32) / 32)] = '0';
	vars->map[(((vars->pos_square_y - 32) / 32) + 1)]
	[((vars->pos_square_x - 32) / 32)] = 'P';
	vars->pos_square_y = vars->pos_square_y + 32;
	if (shine == 1)
		ft_put_square(vars, image, 5);
	else
		ft_put_square(vars, image, 4);
}

// Here I walk through the map to find the players x and y parameters.

void	ft_walk(t_prgrm *vars, t_image *image, int direction)
{
	int		x;
	int		y;
	char	*moves;
	char	*moves_2;

	x = 0;
	y = 0;
	while (ft_strchr(vars->map[y], 'P') == 0)
		y++;
	while (vars->map[y][x] != 'P')
		x++;
	vars->pos_square_x = 32 + (x * 32);
	vars->pos_square_y = 32 + (y * 32);
	if (direction == 0)
		ft_walk_up(vars, image);
	else if (direction == 1)
		ft_walk_left(vars, image);
	else if (direction == 2)
		ft_walk_down(vars, image);
	else if (direction == 3)
		ft_walk_right(vars, image);
	if (vars->moves == 0)
		mlx_string_put(vars->mlx, vars->mlx_win, ((vars->x / 2) * 32), ((vars->y * 32) + 64), 0xFFFFFFFF, "MOVES:");
	vars->moves++;
	moves = ft_itoa(vars->moves);
	if (vars->moves > 0)
	{
		moves_2 = ft_itoa(vars->moves - 1);
		mlx_string_put(vars->mlx, vars->mlx_win, ((vars->x / 2) * 32) + 64, ((vars->y * 32) + 64), 0x00000000, moves_2);
		free (moves_2);
		free (moves);
	}
	mlx_string_put(vars->mlx, vars->mlx_win, ((vars->x / 2) * 32) + 64, ((vars->y * 32) + 64), 0xFFFFFFFF, moves);
}
