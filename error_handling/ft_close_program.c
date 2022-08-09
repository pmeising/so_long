/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_program.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:51:36 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/09 22:28:36 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_images(t_prgrm *vars, t_image *image)
{
		mlx_destroy_image(vars->mlx, image->floor);
		mlx_destroy_image(vars->mlx, image->c1);
		mlx_destroy_image(vars->mlx, image->c2);
		mlx_destroy_image(vars->mlx, image->wall);
		mlx_destroy_image(vars->mlx, image->player);
		mlx_destroy_image(vars->mlx, image->exit);
		mlx_destroy_image(vars->mlx, image->wall_flame);
		mlx_destroy_image(vars->mlx, image->barrel);
}

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

int	ft_close_program(t_prgrm *vars, int ecode)
{
	if (ecode == 1)
		exit(0);
	else if (ecode == 2)
		ft_invalid_map(vars);
	else if (ecode == 3)
		ft_map_not_found(vars);
	ft_free_map(vars);
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit (0);
}
