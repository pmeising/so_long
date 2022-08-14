/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:50:13 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/14 15:44:41 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hooks(t_prgrm *vars)
{
	mlx_hook(vars->mlx_win, 17, 0, ft_close_program, vars);
}

int	ft_key_hook(int keycode, t_prgrm *vars)
{
	if (keycode == 119 || keycode == 65362)
	{
		ft_walk(vars, 0);
	}
	if (keycode == 97 || keycode == 65361)
	{
		ft_walk(vars, 1);
	}
	if (keycode == 115 || keycode == 65364)
	{
		ft_walk(vars, 2);
	}
	if (keycode == 100 || keycode == 65363)
	{
		ft_walk(vars, 3);
	}
	if (keycode == 65307)
		ft_close_program(vars, 0);
	return (keycode);
}
