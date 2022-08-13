/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement_villain.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 20:56:26 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/13 17:49:43 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// void	ft_helper_8_villain(t_prgrm *vars)
// {
// 	int	i;
// 	int	coin;

// 	i = 1;
// 	coin = 0;
// 	if (vars->map[((vars->pos_square_y - 32) / 32)]
// 		[(((vars->pos_square_x - 32) / 32) + 1)] == 'C')
// 		coin = 1;
// 	ft_put_square(vars, 0);
// 	while (i < 7)
// 	{
// 		vars->pos_square_x = vars->pos_square_x - 2;
// 		ft_put_square_walk_left_villain(vars, i - 1);
// 		vars->pos_square_x = vars->pos_square_x + 2;
// 		ft_put_square(vars, 0);
// 		vars->pos_square_x = vars->pos_square_x - 2;
// 		usleep(15000);
// 		i++;
// 	}
// 	vars->pos_square_x = vars->pos_square_x + 32;
// 	if (coin == 1)
// 		ft_put_square(vars, 2);
// 	else
// 		ft_put_square(vars, 0);
// }

// int	ft_helper_9_villain(t_prgrm *vars)
// {
// 	int	i;
// 	int	coin;

// 	i = 1;
// 	coin = 0;
// 	if (vars->map[((vars->pos_square_y - 32) / 32)]
// 		[(((vars->pos_square_x - 32) / 32) - 1)] == 'C')
// 		coin = 1;
// 	ft_put_square(vars, 0);
// 	while (i < 7)
// 	{
// 		vars->pos_square_x = vars->pos_square_x + 2;
// 		ft_put_square_walk_right_villain(vars, i - 1);
// 		vars->pos_square_x = vars->pos_square_x - (i * 2);
// 		ft_fill_floor_right(vars, i - 1);
// 		vars->pos_square_x = vars->pos_square_x + (i * 2);
// 		usleep(15000);
// 		i++;
// 	}
// 	vars->pos_square_x = vars->pos_square_x - 32;
// 	if (coin == 1)
// 		ft_put_square(vars, 2);
// 	else
// 		ft_put_square(vars, 0);
// 	return (coin);
// }

// void	ft_walk_villain_left(t_prgrm *vars)
// {
// 	int	coin;

// 	if (vars->map[((vars->pos_square_y - 32) / 32)]
// 		[(((vars->pos_square_x - 32) / 32) - 1)] != '0' &&
// 		vars->map[((vars->pos_square_y - 32) / 32)]
// 		[(((vars->pos_square_x - 32) / 32) - 1)] != 'C')
// 	{
// 		vars->dir_vil = 1;
// 		return ;
// 	}
// 	coin = ft_helper_8_villain(vars);
// 	if (coin == 0)
// 	{
// 	vars->map[((vars->pos_square_y - 32) / 32)]
// 	[((vars->pos_square_x - 32) / 32)] = '0';
// 	}
// 	else
// 	vars->map[((vars->pos_square_y - 32) / 32)]
// 	[(((vars->pos_square_x - 32) / 32) - 1)] = 'V';
// 	vars->pos_square_x = vars->pos_square_x - 32;
// }

// // void	ft_walk_villain_right(t_prgrm *vars)
// {
// 	if (vars->map[((vars->pos_square_y - 32) / 32)]
// 		[(((vars->pos_square_x - 32) / 32) + 1)] != '0' &&
// 		vars->map[((vars->pos_square_y - 32) / 32)]
// 		[(((vars->pos_square_x - 32) / 32) + 1)] != 'C')
// 	{
// 		vars->dir_vil = 2;
// 		return ;
// 	}
// 	ft_helper_9_villain(vars);
// 	vars->map[((vars->pos_square_y - 32) / 32)]
// 	[((vars->pos_square_x - 32) / 32)] = '0';
// 	vars->map[((vars->pos_square_y - 32) / 32)]
// 	[(((vars->pos_square_x - 32) / 32) + 1)] = 'V';
// 	vars->pos_square_x = vars->pos_square_x + 32;
// }