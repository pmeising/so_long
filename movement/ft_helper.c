/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:44:05 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/14 14:10:20 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_helper_0(t_prgrm *vars)
{
	if (vars->map[((vars->pos_square_y - 32) / 32)]
		[(((vars->pos_square_x - 32) / 32) - 1)] == 'C')
		vars->coins--;
}

void	ft_helper_1(t_prgrm *vars)
{
	if (vars->map[((vars->pos_square_y - 32) / 32)]
		[(((vars->pos_square_x - 32) / 32) + 1)] == 'C')
		vars->coins--;
}

void	ft_helper_2(t_prgrm *vars)
{
	if (vars->map[(((vars->pos_square_y - 32) / 32) - 1)]
		[((vars->pos_square_x - 32) / 32)] == 'C')
		vars->coins--;
}

void	ft_helper_3(t_prgrm *vars)
{
	if (vars->map[(((vars->pos_square_y - 32) / 32) + 1)]
		[((vars->pos_square_x - 32) / 32)] == 'C')
		vars->coins--;
}

int	ft_helper_4(t_prgrm *vars)
{
	if (vars->map[((vars->pos_square_y - 32) / 32)]
		[(((vars->pos_square_x - 32) / 32) - 1)] == 'E')
		return (1);
	else
		return (0);
}
