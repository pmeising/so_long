/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_square_walk.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 13:44:33 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/14 13:59:22 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_square_walk_3(t_prgrm *vars, int i, int dir)
{
	if (i == 14 && dir == 2)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/15_l.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 15 && dir == 2)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/16_l.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 14 && dir == 1)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/15_r.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 15 && dir == 1)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/16_r.xpm",
				&vars->size_x, &vars->size_y);
}

void	ft_put_square_walk_left_2(t_prgrm *vars, int i)
{
	if (i == 7)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/08_l.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 8)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/09_l.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 9)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/10_l.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 10)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/11_l.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 11)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/12_l.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 12)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/13_l.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 13)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/14_l.xpm",
				&vars->size_x, &vars->size_y);
	if (i > 13)
		ft_put_square_walk_3(vars, i, 2);
}

void	ft_put_square_walk_left(t_prgrm *vars, int i)
{
	if (i == 0)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/01_l.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 1)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/02_l.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 2)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/03_l.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 3)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/04_l.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 4)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/05_l.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 5)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/06_l.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 6)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/07_l.xpm",
				&vars->size_x, &vars->size_y);
	if (i > 6)
		ft_put_square_walk_left_2(vars, i);
	if (vars->xpm != NULL)
		ft_put_to_window(vars);
}

void	ft_put_square_walk_right_2(t_prgrm *vars, int i)
{
	if (i == 7)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/08_r.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 8)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/09_r.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 9)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/10_r.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 10)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/11_r.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 11)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/12_r.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 12)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/13_r.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 13)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/14_r.xpm",
				&vars->size_x, &vars->size_y);
	if (i > 13)
		ft_put_square_walk_3(vars, i, 1);
}

void	ft_put_square_walk_right(t_prgrm *vars, int i)
{
	if (i == 0)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/01_r.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 1)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/02_r.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 2)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/03_r.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 3)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/04_r.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 4)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/05_r.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 5)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/06_r.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 6)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/07_r.xpm",
				&vars->size_x, &vars->size_y);
	if (i > 6)
		ft_put_square_walk_right_2(vars, i);
	if (vars->xpm != NULL)
		ft_put_to_window(vars);
}
