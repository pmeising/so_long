/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:50:13 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/09 23:19:45 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hooks(t_prgrm *vars)
{
	mlx_hook(vars->mlx_win, 17, 0, ft_close_program, vars);
}

int	ft_key_hook(int keycode, t_prgrm *vars, t_image *image)
{
	if (keycode == 119)
	{
		ft_walk(vars, image, 0);
	}
	if (keycode == 97)
	{
		ft_walk(vars, image, 1);
	}
	if (keycode == 115)
	{
		ft_walk(vars, image, 2);
	}
	if (keycode == 100)
	{
		ft_walk(vars, image, 3);
	}
	if (keycode == 65307)
		ft_close_program(vars, 0);
	return (keycode);
}
