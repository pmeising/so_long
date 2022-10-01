/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_program.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:51:36 by pmeising          #+#    #+#             */
/*   Updated: 2022/10/02 00:28:53 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_map(t_prgrm *vars)
{
	int	i;

	i = 0;
	if (vars->map)
	{
		while (vars->map[i] != NULL)
		{
			free (vars->map[i]);
			i++;
		}
		free(vars->map);
	}
}

void	ft_invalid_map(t_prgrm *vars)
{
	mlx_destroy_display(vars->mlx);
	if (vars->mlx_win)
		mlx_destroy_window(vars->mlx, vars->mlx_win);
	ft_free_map(vars);
	free(vars->mlx);
	exit (0);
}

void	ft_map_not_found(t_prgrm *vars)
{
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

void	ft_map_format(t_prgrm *vars)
{
	mlx_destroy_display(vars->mlx);
	free (vars->mlx);
	exit (0);
}

int	ft_close_program(t_prgrm *vars, int ecode)
{
	int		lvl;
	int		steps;
	char	*name;
	int		time;
	char	**envp;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	lvl = 5;
	if (ecode == 1)
		exit(0);
	else if (ecode == 2 || ecode == 4)
		ft_invalid_map(vars);
	else if (ecode == 3)
		ft_map_not_found(vars);
	else if (ecode == 6)
		ft_map_format(vars);
	envp = vars->envp;
	time = (long)tv.tv_sec - vars->start_time;
	lvl = vars->lvl;
	name = vars->username;
	steps = vars->moves;
	while (vars->lvl < 5 && ecode != 7)
	{
		ft_print_records(lvl, name, steps, time);
		ft_free_map(vars);
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		ft_keep_lvls_running(lvl, name, steps, time, envp);
	}
	ft_sort_highscore(vars);
	ft_free_map(vars);
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit (0);
}
