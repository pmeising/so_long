/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_flames.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 12:56:46 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/14 12:56:59 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_flames(t_prgrm *vars)
{
	vars->pos_square_x = ((vars->x / 2) * 32) + 32;
	vars->pos_square_y = 32;
	ft_put_square(vars, 8);
	vars->pos_square_x = ((vars->x / 2) * 32) + 32;
	vars->pos_square_y = (vars->y * 32);
	ft_put_square(vars, 8);
	vars->pos_square_x = 32;
	vars->pos_square_y = ((vars->y / 2) * 32) + 32;
	ft_put_square(vars, 8);
	vars->pos_square_x = vars->x * 32;
	vars->pos_square_y = ((vars->y / 2) * 32) + 32;
	ft_put_square(vars, 8);
	vars->pos_square_x = 0;
	vars->pos_square_y = 0;
}
