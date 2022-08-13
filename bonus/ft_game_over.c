/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_over.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 19:33:31 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/13 21:07:25 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_game_over(t_prgrm *vars)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	vars->pos_square_x = 0;
	vars->pos_square_y = 0;
	while (vars->map[j] != NULL)
	{
		if (i == vars->x)
		{
			j++;
			i = 0;
		}
		vars->pos_square_x = 32 + (i * 32);
		vars->pos_square_y = 32 + (j * 32);
		ft_put_square(vars, 1);
		i++;
	}
	usleep(1000000);
	ft_free_map(vars);
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit (0);
}
