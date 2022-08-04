/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:50:13 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/03 11:34:38 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hooks(t_prgrm *vars)
{
	mlx_hook(vars->mlx_win, 17, 0, ft_close_window, &vars);
	printf("Implemented hook\n");
}

int	ft_key_hook(int keycode, t_prgrm *vars)
{
	if (vars)
		printf(" ");
	if (keycode == 119)
		printf("Player walks up.\n");
	if (keycode == 97)
		printf("Player walks walks to the left.\n");
	if (keycode == 115)
		printf("Player walks down.\n");
	if (keycode == 100)
		printf("Player walks to the right.\n");
	if (keycode == 65307)
		ft_close_window(vars);
	return (keycode);
}
