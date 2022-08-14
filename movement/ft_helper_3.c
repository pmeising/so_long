/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:11:00 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/14 14:11:35 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_helper_10(t_prgrm *vars)
{
	int	i;

	i = 1;
	ft_put_square(vars, 0);
	while (i < 17)
	{
		vars->pos_square_y = vars->pos_square_y - 2;
		if (vars->dir == 1)
			ft_put_square_walk_right(vars, i - 1);
		else if (vars->dir == 2)
			ft_put_square_walk_left(vars, i - 1);
		vars->pos_square_y = vars->pos_square_y + 2;
		ft_put_square(vars, 0);
		vars->pos_square_y = vars->pos_square_y - 2;
		usleep(9000);
		i++;
	}
	vars->pos_square_y = vars->pos_square_y + 32;
	ft_put_square(vars, 0);
}

void	ft_helper_11(t_prgrm *vars)
{
	int	i;

	i = 1;
	ft_put_square(vars, 0);
	while (i < 17)
	{
		vars->pos_square_y = vars->pos_square_y + 2;
		ft_put_square_walk_right(vars, i - 1);
		vars->pos_square_y = vars->pos_square_y - 2;
		ft_put_square(vars, 0);
		vars->pos_square_y = vars->pos_square_y + 2;
		usleep(9000);
		i++;
	}
	vars->pos_square_y = vars->pos_square_y - 32;
	ft_put_square(vars, 0);
}
