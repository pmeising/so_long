/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 22:25:31 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/13 22:26:00 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_left_over(t_prgrm *vars)
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
	ft_put_square(vars, 0);
}
