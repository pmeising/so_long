/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_over.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 19:33:31 by pmeising          #+#    #+#             */
/*   Updated: 2022/09/29 19:55:21 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_write_steps(t_prgrm *vars)
{
	char	*steps;

	ft_printf("Entering here.\n");
	steps = ft_itoa(vars->moves);
	ft_printf("steps: %s\n", steps);
	if ((vars->log_file = open("./log/record", O_RDWR | O_APPEND, 0644)) == -1)
		ft_printf("Couldn't open log file.\n");
	write(vars->log_file, ",", 1);
	close(vars->log_file);
	// write(vars->log_file, steps, ft_strlen(steps));
}

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
	ft_write_steps(vars);
	ft_free_map(vars);
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit (0);
}
