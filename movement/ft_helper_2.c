/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 21:40:47 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/09 21:57:54 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_helper_4(t_prgrm *vars)
{
	if (vars->map[((vars->pos_square_y - 32) / 32)]
		[(((vars->pos_square_x - 32) / 32) - 1)] == 'E')
		return (1);
	else
		return (0);
}

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
