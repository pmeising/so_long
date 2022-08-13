/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_over.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 19:33:31 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/13 20:39:01 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_game_over(t_prgrm *vars)
{
	int		i;
	int		j;
	char	*moves_2;

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
	moves_2 = ft_itoa(vars->moves - 1);
	mlx_string_put(vars->mlx, vars->mlx_win, ((vars->x / 2) * 32) + 64, ((vars->y * 32) + 64), 0x00000000, moves_2);
	free (moves_2);
	mlx_string_put(vars->mlx, vars->mlx_win, ((vars->x / 2) * 32) + 64, ((vars->y * 32) + 64), 0xFFFFFFFF, "GAME OVER.\nYOU LOST.");
	// ft_free_map()
}
