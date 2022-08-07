/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_program.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:51:36 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/07 22:56:34 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_images(t_prgrm *vars, t_image *image)
{
	mlx_destroy_image(vars->mlx, image->floor);
	mlx_destroy_image(vars->mlx, image->c1);
	mlx_destroy_image(vars->mlx, image->wall);
	mlx_destroy_image(vars->mlx, image->player);
	mlx_destroy_image(vars->mlx, image->exit);
	mlx_destroy_image(vars->mlx, image->c2);
	mlx_destroy_image(vars->mlx, image->wall_flame);
	mlx_destroy_image(vars->mlx, image->barrel);
}

void	ft_free_map(t_prgrm *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
	{
		free (vars->map[i]);
		i++;
	}
	free(vars->map);
}

int	ft_close_program(t_prgrm *vars, t_image *image)
{
	ft_free_images(vars, image);
	mlx_destroy_display(vars->mlx);
	ft_free_map(vars);
	free(vars->mlx);
	exit (0);
}
