/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_square_villain.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:23:51 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/14 15:26:32 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_square_walk_left_villain(t_prgrm *vars, int i)
{
	if (i == 0)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/Enemy/01_l.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 1)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/Enemy/02_l.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 2)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/Enemy/03_l.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 3)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/Enemy/04_l.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 4)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/Enemy/05_l.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 5)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/Enemy/06_l.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 6)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/Enemy/07_l.xpm",
				&vars->size_x, &vars->size_y);
	if (vars->xpm != NULL)
		ft_put_to_window(vars);
}

void	ft_put_square_walk_right_villain(t_prgrm *vars, int i)
{
	if (i == 0)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/Enemy/01_r.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 1)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/Enemy/02_r.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 2)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/Enemy/03_r.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 3)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/Enemy/04_r.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 4)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/Enemy/05_r.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 5)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/Enemy/06_r.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 6)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/Enemy/07_r.xpm",
				&vars->size_x, &vars->size_y);
	if (vars->xpm != NULL)
		ft_put_to_window(vars);
}
