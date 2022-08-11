/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:03:07 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/11 21:01:29 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_square(t_prgrm *vars, int i)
{
	if (i == 0)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/floor.xpm", &vars->size_x, &vars->size_y);
	else if (i == 1)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/Wall.xpm", &vars->size_x, &vars->size_y);
	else if (i == 2)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/coin_1.xpm", &vars->size_x, &vars->size_y);
	else if (i == 3)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/Exit.xpm", &vars->size_x, &vars->size_y);
	else if (i == 4)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/bear_right.xpm", &vars->size_x, &vars->size_y);
	else if (i == 5)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/bear_right_shine.xpm", &vars->size_x, &vars->size_y);
	else if (i == 6)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/bear_left.xpm", &vars->size_x, &vars->size_y);
	else if (i == 7)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/bear_left_shine.xpm", &vars->size_x, &vars->size_y);
	else if (i == 8)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/Flame.xpm", &vars->size_x, &vars->size_y);
	if (vars->xpm != NULL)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->xpm, vars->pos_square_x, vars->pos_square_y);
		mlx_destroy_image(vars->mlx, vars->xpm);
	}
}

void	ft_put_square_loop(t_prgrm *vars, int i)
{
	if (i == 0)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/01_r.xpm", &vars->size_x, &vars->size_y);
	else if (i == 1)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/02_r.xpm", &vars->size_x, &vars->size_y);
	else if (i == 2)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/03_r.xpm", &vars->size_x, &vars->size_y);
	else if (i == 3)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/04_r.xpm", &vars->size_x, &vars->size_y);
	else if (i == 4)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/05_r.xpm", &vars->size_x, &vars->size_y);
	else if (i == 5)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/06_r.xpm", &vars->size_x, &vars->size_y);
	else if (i == 6)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/07_r.xpm", &vars->size_x, &vars->size_y);
	else if (i == 7)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/08_r.xpm", &vars->size_x, &vars->size_y);
	else if (i == 8)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/01_l.xpm", &vars->size_x, &vars->size_y);
	else if (i == 9)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/02_l.xpm", &vars->size_x, &vars->size_y);
	else if (i == 10)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/03_l.xpm", &vars->size_x, &vars->size_y);
	else if (i == 11)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/04_l.xpm", &vars->size_x, &vars->size_y);
	else if (i == 12)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/05_l.xpm", &vars->size_x, &vars->size_y);
	else if (i == 13)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/06_l.xpm", &vars->size_x, &vars->size_y);
	else if (i == 14)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/07_l.xpm", &vars->size_x, &vars->size_y);
	else if (i == 15)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/08_l.xpm", &vars->size_x, &vars->size_y);
	if (vars->xpm != NULL)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->xpm, vars->pos_square_x, vars->pos_square_y);
		mlx_destroy_image(vars->mlx, vars->xpm);
	}
}

void	ft_put_square_loop_walk_left(t_prgrm *vars, int i)
{
	if (i == 0)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/01_l.xpm", &vars->size_x, &vars->size_y);
	else if (i == 1)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/02_l.xpm", &vars->size_x, &vars->size_y);
	else if (i == 2)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/03_l.xpm", &vars->size_x, &vars->size_y);
	else if (i == 3)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/04_l.xpm", &vars->size_x, &vars->size_y);
	else if (i == 4)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/05_l.xpm", &vars->size_x, &vars->size_y);
	else if (i == 5)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/06_l.xpm", &vars->size_x, &vars->size_y);
	else if (i == 6)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/07_l.xpm", &vars->size_x, &vars->size_y);
	else if (i == 7)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/08_l.xpm", &vars->size_x, &vars->size_y);
	else if (i == 8)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/09_l.xpm", &vars->size_x, &vars->size_y);
	else if (i == 9)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/10_l.xpm", &vars->size_x, &vars->size_y);
	else if (i == 10)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/11_l.xpm", &vars->size_x, &vars->size_y);
	else if (i == 11)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/12_l.xpm", &vars->size_x, &vars->size_y);
	else if (i == 12)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/13_l.xpm", &vars->size_x, &vars->size_y);
	else if (i == 13)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/14_l.xpm", &vars->size_x, &vars->size_y);
	else if (i == 14)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/15_l.xpm", &vars->size_x, &vars->size_y);
	else if (i == 15)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/16_l.xpm", &vars->size_x, &vars->size_y);
	if (vars->xpm != NULL)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->xpm, vars->pos_square_x, vars->pos_square_y);
		mlx_destroy_image(vars->mlx, vars->xpm);
	}
}

void	ft_put_square_loop_walk_right(t_prgrm *vars, int i)
{
	if (i == 0)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/01_r.xpm", &vars->size_x, &vars->size_y);
	else if (i == 1)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/02_r.xpm", &vars->size_x, &vars->size_y);
	else if (i == 2)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/03_r.xpm", &vars->size_x, &vars->size_y);
	else if (i == 3)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/04_r.xpm", &vars->size_x, &vars->size_y);
	else if (i == 4)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/05_r.xpm", &vars->size_x, &vars->size_y);
	else if (i == 5)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/06_r.xpm", &vars->size_x, &vars->size_y);
	else if (i == 6)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/07_r.xpm", &vars->size_x, &vars->size_y);
	else if (i == 7)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/08_r.xpm", &vars->size_x, &vars->size_y);
	else if (i == 8)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/09_r.xpm", &vars->size_x, &vars->size_y);
	else if (i == 9)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/10_r.xpm", &vars->size_x, &vars->size_y);
	else if (i == 10)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/11_r.xpm", &vars->size_x, &vars->size_y);
	else if (i == 11)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/12_r.xpm", &vars->size_x, &vars->size_y);
	else if (i == 12)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/13_r.xpm", &vars->size_x, &vars->size_y);
	else if (i == 13)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/14_r.xpm", &vars->size_x, &vars->size_y);
	else if (i == 14)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/15_r.xpm", &vars->size_x, &vars->size_y);
	else if (i == 15)
		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/16_r.xpm", &vars->size_x, &vars->size_y);
	if (vars->xpm != NULL)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->xpm, vars->pos_square_x, vars->pos_square_y);
		mlx_destroy_image(vars->mlx, vars->xpm);
	}
}

void	ft_put_flames(t_prgrm *vars)
{
	vars->pos_square_x = ((vars->x / 2) * 32) + 32;
	vars->pos_square_y = 32;
	ft_put_square(vars, 8);
	vars->pos_square_x = ((vars->x / 2) * 32) + 32;
	vars->pos_square_y = (vars->y * 32);
	ft_put_square(vars, 8);
	vars->pos_square_x = 32;
	vars->pos_square_y = ((vars->y / 2) * 32) + 32;
	ft_put_square(vars, 8);
	vars->pos_square_x = vars->x * 32;
	vars->pos_square_y = ((vars->y / 2) * 32) + 32;
	ft_put_square(vars, 8);
	vars->pos_square_x = 0;
	vars->pos_square_y = 0;
}
