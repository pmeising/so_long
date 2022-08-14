/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:03:07 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/14 14:01:47 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_to_window(t_prgrm *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->xpm,
		vars->pos_square_x, vars->pos_square_y);
	mlx_destroy_image(vars->mlx, vars->xpm);
}

void	ft_put_square(t_prgrm *vars, int i)
{
	if (i == 0)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/floor.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 1)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/Wall.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 2)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/coin_1.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 3)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/Exit.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 4)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/bear_right.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 6)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/bear_left.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 8)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/Flame.xpm",
				&vars->size_x, &vars->size_y);
	if (vars->xpm != NULL)
		ft_put_to_window(vars);
}

void	ft_fill_floor_right_3(t_prgrm *vars, int i)
{
	if (i == 14)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/ws/15_r.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 15)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/ws/15_r.xpm",
				&vars->size_x, &vars->size_y);
}

void	ft_fill_floor_right_2(t_prgrm *vars, int i)
{
	if (i == 7)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/ws/08_r.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 8)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/ws/09_r.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 9)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/ws/10_r.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 10)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/ws/11_r.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 11)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/ws/12_r.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 12)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/ws/13_r.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 13)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/ws/14_r.xpm",
				&vars->size_x, &vars->size_y);
	if (i > 13)
		ft_fill_floor_right_3(vars, i);
}

void	ft_fill_floor_right(t_prgrm *vars, int i)
{
	if (i == 0)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/ws/01_r.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 1)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/ws/02_r.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 2)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/ws/03_r.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 3)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/ws/04_r.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 4)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/ws/05_r.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 5)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/ws/06_r.xpm",
				&vars->size_x, &vars->size_y);
	else if (i == 6)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/ws/07_r.xpm",
				&vars->size_x, &vars->size_y);
	if (i > 6)
		ft_fill_floor_right_2(vars, i);
	if (vars->xpm != NULL)
		ft_put_to_window(vars);
}
