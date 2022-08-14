/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 21:40:47 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/14 15:27:27 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_helper_5(t_prgrm *vars)
{
	if (vars->map[((vars->pos_square_y - 32) / 32)]
		[(((vars->pos_square_x - 32) / 32) + 1)] == 'E')
		return (1);
	else
		return (0);
}

int	ft_helper_6(t_prgrm *vars)
{
	if (vars->map[(((vars->pos_square_y - 32) / 32) - 1)]
		[((vars->pos_square_x - 32) / 32)] == 'E')
		return (1);
	else
		return (0);
}

int	ft_helper_7(t_prgrm *vars)
{
	if (vars->map[(((vars->pos_square_y - 32) / 32) + 1)]
		[((vars->pos_square_x - 32) / 32)] == 'E')
		return (1);
	else
		return (0);
}

void	ft_helper_8(t_prgrm *vars)
{
	int	i;

	i = 1;
	ft_put_square(vars, 0);
	while (i < 17)
	{
		vars->pos_square_x = vars->pos_square_x - 2;
		ft_put_square_walk_left(vars, i - 1);
		vars->pos_square_x = vars->pos_square_x + 2;
		ft_put_square(vars, 0);
		vars->pos_square_x = vars->pos_square_x - 2;
		usleep(9000);
		i++;
	}
	vars->pos_square_x = vars->pos_square_x + 32;
	ft_put_square(vars, 0);
}

void	ft_helper_9(t_prgrm *vars)
{
	int	i;

	i = 1;
	ft_put_square(vars, 0);
	while (i < 17)
	{
		vars->pos_square_x = vars->pos_square_x + 2;
		ft_put_square_walk_right(vars, i - 1);
		vars->pos_square_x = vars->pos_square_x - (i * 2);
		ft_fill_floor_right(vars, i - 1);
		vars->pos_square_x = vars->pos_square_x + (i * 2);
		usleep(9000);
		i++;
	}
	vars->pos_square_x = vars->pos_square_x - 32;
	ft_put_square(vars, 0);
}
